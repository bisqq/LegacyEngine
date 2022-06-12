#pragma once

#ifndef VULKAN_BACKEND
#define VULKAN_BACKEND

#include "vulkan/vulkan.h"

#endif // !VULKAN_BACKEND

namespace VulkanFrontend {
	namespace Draw {
		void drawFrame();
		void createSyncObjects();
	}

	namespace VertexBuffer {
		void createVertexBuffer();
		void createIndexBuffer();
	}

	namespace UniformBuffer {
		void createUniformBuffers();
		void createDescriptorSetLayout();
		void createDescriptorPool();
		void createDescriptorSets();
	}

	namespace Textures {
		void createTextureImage();
		void createTextureImageView();
		void createTextureSampler();
	}

	namespace DepthBuffer {
		void createDepthResources();
	}

	namespace LoadModels {
		void loadModel();
	}

	namespace Multisampling {
		void createColorResources();
	}
}