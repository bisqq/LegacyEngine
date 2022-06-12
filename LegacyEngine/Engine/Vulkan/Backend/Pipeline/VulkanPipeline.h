#pragma once

#ifndef VULKAN_PIPELINE
#define VULKAN_PIPELINE

#include "vulkan/vulkan.h"
#include <vector>
#include <string>

class VulkanPipline {
	VkShaderModule createShaderModule(const std::vector<char>& code);
	static std::vector<char> readFile(const std::string& filename);
};


#endif // !VULKAN_PIPELINE
