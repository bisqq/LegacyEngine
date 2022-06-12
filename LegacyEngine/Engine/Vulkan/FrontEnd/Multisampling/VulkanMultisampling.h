#pragma once

#ifndef VULKAN_MULTISAMPLING
#define VULKAN_MULTISAMPLING

#include "vulkan/vulkan.h"

class VulkanMultisampling {
	VkSampleCountFlagBits getMaxUsableSampleCount();
};

#endif // !VULKAN_MULTISAMPLING
