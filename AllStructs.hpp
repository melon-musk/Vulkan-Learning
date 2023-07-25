#pragma once
#include<vulkan/vulkan.h>
#include<vector>
#include<optional>


struct SwapChainSupportDetails
{
    //(min / max number of images in swap chain, min / max width and height of images)
    VkSurfaceCapabilitiesKHR capabilities;
    //colourSpace and pixel formats
    std::vector<VkSurfaceFormatKHR> surfaceFormats;
    //FIFO, mailbox etc
    std::vector<VkPresentModeKHR> presentModes;
};