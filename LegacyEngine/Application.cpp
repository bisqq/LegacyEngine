#include <Windows.h> // for console

#define LEGACY_DEBUG
#include "Libraries/Debugging.h"
#include "Vendor/Glfw/glfw3.h"
#include "Core/Include/GuiSystem.h"

static GLFWwindow* window;
static GuiSystem guiSystem;

void updateViewPort();
void BeginGlfw();
void WindowLoop();
void ShutdownGlfw();

//int main() {
//#if !_DEBUG
//	auto myConsole = GetConsoleWindow();
//	ShowWindow(myConsole, 0);
//#endif
//
//  BeginGlfw();
//	WindowLoop();
//	ShutdownGlfw();
//}

void updateViewPort() {
	glfwSwapBuffers(window);
	glClear(GL_COLOR_BUFFER_BIT);
}

void onGlfwWindowResized(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	updateViewPort();
}

void windowRefreshFun(GLFWwindow* window) {
	updateViewPort();
}

void BeginGlfw() {
	glfwInit();
	//glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	window = glfwCreateWindow(1280, 720, "Legacy Engine", nullptr, nullptr);

	if (nullptr == window) {
		LOG("Failed to create GLFW window\n");
		ShutdownGlfw();
		return;
	}

	glfwMakeContextCurrent(window);
	//glfwSwapInterval(1);

	glfwSetWindowRefreshCallback(window, windowRefreshFun);

	if (!glfwVulkanSupported()) {
		LOG("GLFW: Vulkan Not Supported\n");
		return;
	}
}

void WindowLoop() {
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		
		guiSystem.RenderGui();

		updateViewPort();
	}
}

void ShutdownGlfw() {
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}