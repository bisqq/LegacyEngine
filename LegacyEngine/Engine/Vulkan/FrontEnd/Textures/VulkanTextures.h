#pragma once

#ifndef VULKAN_TEXTURES
#define VULKAN_TEXTURES

#include "vulkan/vulkan.h"

class VulkanTextures {
    void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format,
        VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
    VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
    VkCommandBuffer beginSingleTimeCommands();
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
};

#endif // !VULKAN_TEXTURES
