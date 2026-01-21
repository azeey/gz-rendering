/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <mutex>
#include <vector>

#if __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/OpenGL.h>
#elif _WIN32
  #define NOMINMAX
  #include <windows.h>
  #include <GL/glew.h>
  #include <GL/glu.h>
  #include "Wingdi.h"
#else
  #include <GL/glew.h>
  #include <GL/gl.h>
#endif

#if !defined(__APPLE__) && !defined(_WIN32)
  #include <GL/glx.h>
#endif

#include <GLFW/glfw3.h>

#include <gz/common/Console.hh>
#include <gz/rendering/Camera.hh>
#include <gz/rendering/Image.hh>
#include <gz/rendering/Scene.hh>

#include "GlfwWindow.hh"

//////////////////////////////////////////////////
unsigned int imgw = 0;
unsigned int imgh = 0;

std::vector<ir::CameraPtr> g_cameras;
ir::CameraPtr g_camera;
unsigned int g_cameraIndex = 0;
ir::ImagePtr g_image;

#if __APPLE__
  CGLContextObj g_context;
  CGLContextObj g_glfwContext;
#elif _WIN32
  HGLRC g_context = 0;
  HDC g_display = 0;
  HGLRC g_glfwContext = 0;
  HDC g_glfwDisplay = 0;
#else
  GLXContext g_context;
  Display *g_display;
  GLXDrawable g_drawable;
  GLXContext g_glfwContext;
  Display *g_glfwDisplay;
  GLXDrawable g_glfwDrawable;
#endif

double g_offset = 0.0;

//////////////////////////////////////////////////
//! [update camera]
void updateCameras()
{
  double angle = g_offset / 2 * GZ_PI;
  double x = sin(angle) * 3.0 + 3.0;
  double y = cos(angle) * 3.0;
  for (ir::CameraPtr camera : g_cameras)
  {
    camera->SetLocalPosition(x, y, 0.0);
  }

  g_offset += 0.0005;
}
//! [update camera]

//////////////////////////////////////////////////
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (action == GLFW_PRESS)
  {
    if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q)
    {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (key == GLFW_KEY_TAB)
    {
      g_cameraIndex = (g_cameraIndex + 1) % g_cameras.size();
    }
  }
}

//////////////////////////////////////////////////
void initCamera(ir::CameraPtr _camera)
{
  g_camera = _camera;
  imgw = g_camera->ImageWidth();
  imgh = g_camera->ImageHeight();
  ir::Image image = g_camera->CreateImage();
  g_image = std::make_shared<ir::Image>(image);
  g_camera->Capture(*g_image);
}

//////////////////////////////////////////////////
void printUsage()
{
  std::cout << "===============================" << std::endl;
  std::cout << "  TAB - Switch render engines  " << std::endl;
  std::cout << "  ESC - Exit                   " << std::endl;
  std::cout << "===============================" << std::endl;
}

//////////////////////////////////////////////////
void run(std::vector<ir::CameraPtr> _cameras)
{
  if (_cameras.empty())
  {
    gzerr << "No cameras found. Scene will not be rendered" << std::endl;
    return;
  }

#if __APPLE__
  g_context = CGLGetCurrentContext();
#elif _WIN32
  g_context = wglGetCurrentContext();
  g_display = wglGetCurrentDC();
#else
  g_context = glXGetCurrentContext();
  g_display = glXGetCurrentDisplay();
  g_drawable = glXGetCurrentDrawable();
#endif

  g_cameras = _cameras;
  initCamera(_cameras[0]);

  if (!glfwInit())
  {
    gzerr << "Error initializing GLFW" << std::endl;
    return;
  }

  GLFWwindow* window = glfwCreateWindow(imgw, imgh, "Simple Demo", NULL, NULL);
  if (!window)
  {
    gzerr << "Error creating GLFW window" << std::endl;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);

#if __APPLE__
  g_glfwContext = CGLGetCurrentContext();
#elif _WIN32
  g_glfwContext = wglGetCurrentContext();
  g_glfwDisplay = wglGetCurrentDC();
#else
  g_glfwDisplay = glXGetCurrentDisplay();
  g_glfwDrawable = glXGetCurrentDrawable();
  g_glfwContext = glXGetCurrentContext();
#endif

  printUsage();

  while (!glfwWindowShouldClose(window))
  {
#if __APPLE__
    CGLSetCurrentContext(g_context);
#elif _WIN32
    if (!wglMakeCurrent(g_display, g_context))
    {
      std::cerr << "Error calling wglMakeCurrent" << '\n';
      break;
    }
#else
    if (g_display)
    {
      glXMakeCurrent(g_display, g_drawable, g_context);
    }
#endif

    g_cameras[g_cameraIndex]->Capture(*g_image);

#if __APPLE__
    CGLSetCurrentContext(g_glfwContext);
#elif _WIN32
    wglMakeCurrent(g_glfwDisplay, g_glfwContext);
#else
    glXMakeCurrent(g_glfwDisplay, g_glfwDrawable, g_glfwContext);
#endif

    unsigned char *data = g_image->Data<unsigned char>();

    glClearColor(0.5, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPixelZoom(1, -1);
    glRasterPos2f(-1, 1);
    glDrawPixels(imgw, imgh, GL_RGB, GL_UNSIGNED_BYTE, data);

    glfwSwapBuffers(window);
    glfwPollEvents();
    updateCameras();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}
