#pragma once
#include<optional>
#include<vulkan/vulkan.h>
#include<vector>

class QueueFamilyIndices
{
    std::optional<uint32_t> mGraphicsFamily;
    std::optional<uint32_t> mPresentationFamily;
    std::optional<uint32_t> mTransferFamily;

public: 
    QueueFamilyIndices(VkPhysicalDevice& device, VkSurfaceKHR& surafce);
    QueueFamilyIndices();
    bool isComplete();
    uint32_t getGraphicsFamily();
    uint32_t getPresentationFamily();
    uint32_t getTransferFamily();
};