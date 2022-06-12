#pragma once

#ifndef VULKAN_MIPMAPS
#define VULKAN_MIPMAPS

#include "vulkan/vulkan.h"

class VulkanMipmaps {
	void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
};

#endif // !VULKAN_MIPMAPS
