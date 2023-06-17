#include "WindowingSystem.hpp"

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
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		WindowSys::window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	bool WindowSys::shouldClose()
	{
		return glfwWindowShouldClose(WindowSys::window);
	}

	GLFWwindow* WindowSys::getGLFWwindow()
	{
		return window;
	}


