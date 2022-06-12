#pragma once

#ifndef VULKAN_DEPTH_BUFFER
#define VULKAN_DEPTH_BUFFER

#include "vulkan/vulkan.h"
#include <vector>

class VulkanDepthBuffer {
    VkFormat findDepthFormat();
    bool hasStencilComponent(VkFormat format);
    VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

};

#endif // !VULKAN_DEPTH_BUFFER
