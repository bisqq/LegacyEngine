#pragma once

#ifndef APPLICATION
#define APPLICATION

#include "DearImGui/imgui.h"

class Legacy {
public:
	void RenderGui();

private:
	void Docking();
	void MenuBar();

private:
	bool opt_fullscreen = true;
	bool opt_padding = false;
	ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
};

#endif // !APPLICATION
