#include <Windows.h> // for console

#define LEGACY_DEBUG
#include "Libraries/Debugging.h"
#include "Vendor/Glfw/glfw3.h"
#include "Vendor/DearImGui/imgui.h"

static GLFWwindow* window;

void updateViewPort();
void BeginGlfw();
void WindowLoop();
void ShutdownGlfw();
void ImGuiRender();

//int main() {
//#if !_DEBUG
//	auto myConsole = GetConsoleWindow();
//	ShowWindow(myConsole, 0);
//#endif
//
//    BeginGlfw();
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
		ImGuiRender();
		updateViewPort();
	}
}

void ImGuiRender() {
	// Start the Dear ImGui frame
	ImGui::NewFrame();

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }

    // 3. Show another simple window.
    if (show_another_window)
    {
        ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_another_window = false;
        ImGui::End();
    }

    // Rendering
    ImGui::Render();
}

void ShutdownGlfw() {
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}