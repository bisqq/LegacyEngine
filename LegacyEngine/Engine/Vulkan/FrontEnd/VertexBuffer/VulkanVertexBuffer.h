#pragma once

#ifndef VULKAN_VERTEX_BUFFER
#define VULKAN_VERTEX_BUFFER

#include "vulkan/vulkan.h"

class VulkanVertexBuffer {
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

};

#endif // !VULKAN_VERTEX_BUFFER
