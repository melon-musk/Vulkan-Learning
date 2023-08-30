#include "WindowingSystem.hpp"
#include <iostream>


static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	std::cout << "FRAME RESIED " <<std::endl;
	bool* frameBufferResized = (bool*)glfwGetWindowUserPointer(window);
	*frameBufferResized = true;
}

	WindowSys::WindowSys()
	{
		initWindow();
	}

	WindowSys::~WindowSys()
	{
		glfwDestroyWindow(WindowSys::window);
		glfwTerminate();
	}

	void WindowSys::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
		glfwSetFramebufferSizeCallback(WindowSys::window, framebufferResizeCallback);
	}


	bool WindowSys::shouldClose()
	{
		return glfwWindowShouldClose(WindowSys::window);
	}

	void WindowSys::setUserPointer(void* ptr)
	{
		glfwSetWindowUserPointer(window, ptr);
	}

	GLFWwindow* WindowSys::getGLFWwindow()
	{
		return window;
	}


