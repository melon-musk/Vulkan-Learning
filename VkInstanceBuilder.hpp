#pragma once
#include <vulkan/vulkan.h>
#include <iostream>
#include<vector>


	class VkInstanceBuilder
	{
	public:
		void appName(const char* appName);
		void appVersion(uint32_t appVersion);
		void engineName(const char* engineName);
		void engineVersion(uint32_t engineVersion);
		void apiVersion(uint32_t apiVersion);

		void enabledExtensions(std::vector<const char*> &extensions);
		void enabledLayers(std::vector<const char*> &layers);
		VkInstanceCreateInfo build();

		VkInstanceBuilder();

		VkApplicationInfo appInfo{};
		VkInstanceCreateInfo createInfo{};
	};


