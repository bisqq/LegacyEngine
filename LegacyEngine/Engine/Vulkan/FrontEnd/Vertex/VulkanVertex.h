#pragma once

#ifndef VULKAN_VERTEX
#define VULKAN_VERTEX

#include "vulkan/vulkan.h"
#include "glm/glm/glm.hpp"

#include <array>

struct VulkanVertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	VulkanVertex()
		:pos(), color(), texCoord()
	{}

	VulkanVertex(glm::vec3 pos_, glm::vec3 color_, glm::vec2 texCoord_)
		: pos(pos_), color(color_), texCoord(texCoord_)
	{}

	static VkVertexInputBindingDescription getBindingDescription() {
		VkVertexInputBindingDescription VertexInputBindingDescription;

		VertexInputBindingDescription.binding = 0;
		VertexInputBindingDescription.stride = sizeof(VulkanVertex);
		VertexInputBindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return VertexInputBindingDescription;
	}

	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescription() {
		std::array<VkVertexInputAttributeDescription, 3> VertexInputAttributeDescriptions{};

		VertexInputAttributeDescriptions[0].binding = 0;
		VertexInputAttributeDescriptions[0].location = 0;
		VertexInputAttributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		VertexInputAttributeDescriptions[0].offset = offsetof(VulkanVertex, pos);

		VertexInputAttributeDescriptions[1].binding = 0;
		VertexInputAttributeDescriptions[1].location = 1;
		VertexInputAttributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		VertexInputAttributeDescriptions[1].offset = offsetof(VulkanVertex, color);

		VertexInputAttributeDescriptions[2].binding = 0;
		VertexInputAttributeDescriptions[2].location = 2;
		VertexInputAttributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		VertexInputAttributeDescriptions[2].offset = offsetof(VulkanVertex, texCoord);

		return VertexInputAttributeDescriptions;
	}

	bool operator==(const VulkanVertex& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

#endif // !VULKAN_VERTEX