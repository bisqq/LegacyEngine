#pragma once


#ifndef VULKAN_UNIFORM_BUFFER
#define VULKAN_UNIFORM_BUFFER

#include <stdint.h>

class VulkanUniformBuffer {
	void updateUniformBuffer(uint32_t currentImage);
};

#endif // !VULKAN_UNIFORM_BUFFER
