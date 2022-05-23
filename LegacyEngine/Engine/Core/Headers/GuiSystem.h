#pragma once

#ifndef APPLICATION
#define APPLICATION

#include "DearImGui/imgui.h"

class GuiSystem {
public:
	void RenderGui();

private:
	void Docking();
	void MenuBar();
	void SectionBar();
	void AlignButtons();

	enum LegacyWindows {
		MEDIA,
		TEXTURE,
		COLOUR,
		EDIT,
		TIMELINE,
		AUDIO,
		DELIVER
	};

private:
	bool optFullscreen = true;
	bool optPadding = false;

	ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

	LegacyWindows legacyWindows;
};

#endif // !APPLICATION
