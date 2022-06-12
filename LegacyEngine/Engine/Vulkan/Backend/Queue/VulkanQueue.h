#pragma once

#ifndef VULKAN_QUEUE
#define VULKAN_QUEUE

#include "vulkan/vulkan.h"
#include <optional>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() { return graphicsFamily.has_value() && presentFamily.has_value(); }
};

class VulkanQueue {
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
};

#endif // !VULKAN_QUEUE
