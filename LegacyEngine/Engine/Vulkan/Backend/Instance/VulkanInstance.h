#pragma once

#ifndef VULKAN_INSTANCE
#define VULKAN_INSTANCE

#include "vulkan/vulkan.h"
#include <vector>

class VulkanInstance {
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
};

#endif // !VULKAN_INSTANCE
