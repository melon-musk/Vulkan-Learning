#include "VkInstanceBuilder.hpp"
#include<iostream>

	
	VkInstanceBuilder::VkInstanceBuilder()
	{
		//defaults i guess, there's got to be a better way to this
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.enabledExtensionCount = 0;
		//createInfo.ppEnabledExtensionNames = nullptr;
		createInfo.enabledLayerCount = 0;
		//createInfo.ppEnabledLayerNames = nullptr;
		//createInfo.pNext = nullptr;
	}

	void VkInstanceBuilder::enabledExtensions(std::vector<const char*> &extensions)
	{
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();
	}

	void VkInstanceBuilder::enabledLayers(std::vector<const char*> &layers)
	{
		
		createInfo.enabledLayerCount = static_cast<uint32_t>(layers.size());
		createInfo.ppEnabledLayerNames = layers.data();
	}

	//renaming this later since i still don't understand validation layers yet
	void pNext(const void* pNext) {

	}

	void VkInstanceBuilder::appName(const char* appName) {
		appInfo.pApplicationName = appName;
	}
	void VkInstanceBuilder::appVersion(uint32_t appVersion) {
		appInfo.apiVersion = appVersion;
	}

	void VkInstanceBuilder::engineName(const char* engineName) {
		appInfo.pEngineName = engineName;
	}

	void VkInstanceBuilder::engineVersion(uint32_t engineVersion) {
		appInfo.engineVersion = engineVersion;
	}

	void VkInstanceBuilder::apiVersion(uint32_t apiVersion) {
		appInfo.apiVersion = apiVersion;
	}

	VkInstanceCreateInfo VkInstanceBuilder::build()
	{
		createInfo.pApplicationInfo = &appInfo;

		return createInfo;
	}

