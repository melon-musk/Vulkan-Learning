#include "QueueFamilyIndices.hpp"



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

        if (isComplete()) break;
        queue_index++;
    }
}

QueueFamilyIndices::QueueFamilyIndices() {};

bool QueueFamilyIndices::isComplete()
{
	return mGraphicsFamily.has_value() && mPresentationFamily.has_value();
}

uint32_t QueueFamilyIndices::getGraphicsFamily() {
    return mGraphicsFamily.value();
}

uint32_t QueueFamilyIndices::getPresentationFamily() {
    return mPresentationFamily.value();
}