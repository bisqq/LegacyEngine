#pragma once

#ifndef VULKAN_DEVICE
#define VULKAN_DEVICE

#include "vulkan/vulkan.h"

class VulkanDevice {
	bool isDeviceSuitable(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
};

#endif // !VULKAN_DEVICE