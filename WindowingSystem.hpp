#pragma once

#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>


	class WindowSys
	{
	public:
		WindowSys();
		~WindowSys();
		bool shouldClose();
		GLFWwindow* getGLFWwindow();

	private:
		const uint32_t WIDTH = 800;
		const uint32_t HEIGHT = 600;
		GLFWwindow* window;

		void initWindow();
		
	};
