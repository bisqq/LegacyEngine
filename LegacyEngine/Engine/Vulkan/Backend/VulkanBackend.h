#pragma once

#ifndef VULKAN_BACKEND
#define VULKAN_BACKEND

#include "vulkan/vulkan.h"

#endif // !VULKAN_BACKEND


namespace VulkanBackEnd {
	namespace Instance {
		void createInstance();
		void setupDebugMessenger();
		void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
		void createSurface();
	}

	namespace Device {
		void getAllPhysicalDevices();
		void createLogicalDevice();
	}

	namespace Swapchain {
		void createSwapChain();
		void cleanUpSwapChain();
	}

	namespace ImageViews {
		void createImageViews();
	}

	namespace Pipeline {
		void createGuiGraphicsPipeline();
		void createGraphicsPipeline();
		void createRenderPass();
	}

	namespace FrameBuffers {
		void createFramebuffers();
	}

	namespace CommandBuffers {
		void createCommandPool();
		void createCommandBuffers();
	}
}