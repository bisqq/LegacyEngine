#pragma once

#ifndef VULKAN_PRINT_DEBUG
#define VULKAN_PRINT_DEBUG

#include "vulkan/vulkan.h"

struct VulkronPrintDebug {
	void printStats(VkPhysicalDevice& device);
	void printInstanceLayers();
	void printInstanceExtensions();
};

#endif // !VULKAN_PRINT_DEBUG