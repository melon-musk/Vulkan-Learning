#pragma once
#include<optional>
#include<vulkan/vulkan.h>
#include<vector>

class QueueFamilyIndices
{
    std::optional<uint32_t> mGraphicsFamily;
    std::optional<uint32_t> mPresentationFamily;

public: 
    QueueFamilyIndices(VkPhysicalDevice& device, VkSurfaceKHR& surafce);
    QueueFamilyIndices();
    bool isComplete();
    uint32_t getGraphicsFamily();
    uint32_t getPresentationFamily();
};