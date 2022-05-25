
#include "Editor.h"

#include "DearImGui/imgui.h"

Editor::Editor() {
}

Editor::~Editor() {
}

void Editor::RenderEditor() {
    Viewport();
    ContentBrowser();
    ToolBar();
}

void Editor::Viewport() {
    ImGuiWindowFlags EditorFlags = 0;
    EditorFlags |= ImGuiWindowFlags_NoMove;
    EditorFlags |= ImGuiWindowFlags_NoScrollbar;
    EditorFlags |= ImGuiWindowFlags_NoScrollWithMouse;
    EditorFlags |= ImGuiWindowFlags_NoCollapse;

    ImGui::Begin("Viewport", nullptr, EditorFlags);

    ImGui::End();
}

void Editor::ContentBrowser() {
    ImGuiWindowFlags EditorFlags = 0;
    EditorFlags |= ImGuiWindowFlags_NoTitleBar;
    EditorFlags |= ImGuiWindowFlags_NoResize;
    EditorFlags |= ImGuiWindowFlags_NoMove;
    EditorFlags |= ImGuiWindowFlags_NoScrollbar;
    EditorFlags |= ImGuiWindowFlags_NoScrollWithMouse;
    EditorFlags |= ImGuiWindowFlags_NoCollapse;

    ImGui::Begin("##Content Browser", nullptr, EditorFlags);

    if (ImGui::Button("Files", ImVec2(40, 20))) {

    }

    if (ImGui::Button("World Outliner", ImVec2(40, 20))) {

    }

    if (ImGui::Button("Details", ImVec2(40, 20))) {

    }

    ImGui::End();
}

void Editor::ToolBar() {
    ImGuiWindowFlags EditorFlags = 0;
    EditorFlags |= ImGuiWindowFlags_NoTitleBar;
    EditorFlags |= ImGuiWindowFlags_NoResize;
    EditorFlags |= ImGuiWindowFlags_NoMove;
    EditorFlags |= ImGuiWindowFlags_NoScrollbar;
    EditorFlags |= ImGuiWindowFlags_NoScrollWithMouse;
    EditorFlags |= ImGuiWindowFlags_NoCollapse;


    ImGui::Begin("##Tool Bar", nullptr, EditorFlags);

    if (ImGui::Button("Play/Stop", ImVec2(80, 20))) {
    }

    ImGui::End();
}