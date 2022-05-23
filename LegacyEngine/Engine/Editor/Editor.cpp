
#include "Editor.h"

#include "DearImGui/imgui.h"

Editor::Editor() {
}

Editor::~Editor() {
}

void Editor::RenderEditor() {
    ImGuiWindowFlags EditorFlags = 0;
    EditorFlags |= ImGuiWindowFlags_NoDecoration;
    EditorFlags |= ImGuiWindowFlags_NoMove;
    EditorFlags |= ImGuiWindowFlags_NoScrollWithMouse;

    ImGui::Begin("##Editor", nullptr, 0);

    ImGui::End();
}