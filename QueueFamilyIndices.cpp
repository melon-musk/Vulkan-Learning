#include "QueueFamilyIndices.hpp"
#include <iostream>



QueueFamilyIndices::QueueFamilyIndices(VkPhysicalDevice& device, VkSurfaceKHR& surface)
{
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int queue_index = 0;
    for (const auto& queueFamily : queueFamilies) {
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            VkBool32 presentationSupport = false;
            vkGetPhysicalDeviceSurfaceSupportKHR(device, queue_index, surface, &presentationSupport);
            mGraphicsFamily = queue_index;
            if (presentationSupport) mPresentationFamily = queue_index;
        }

        if ((queueFamily.queueFlags & VK_QUEUE_TRANSFER_BIT) && !(queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)) mTransferFamily = queue_index;

        if (isComplete()) break;
        queue_index++;
    }

    //std::cout << "Graphics Family:" << mGraphicsFamily.has_value()<< std::endl;
    //std::cout << "Presentation Family:" << mPresentationFamily.has_value();
    //std::cout << "Transfer Family:" << mTransferFamily.has_value();


}

QueueFamilyIndices::QueueFamilyIndices() {};

bool QueueFamilyIndices::isComplete()
{
	return mGraphicsFamily.has_value() && mPresentationFamily.has_value() && mTransferFamily.has_value();
}

uint32_t QueueFamilyIndices::getGraphicsFamily() {
    return mGraphicsFamily.value();
}

uint32_t QueueFamilyIndices::getPresentationFamily() {
    return mPresentationFamily.value();
}

uint32_t QueueFamilyIndices::getTransferFamily() {
    return mTransferFamily.value();
}