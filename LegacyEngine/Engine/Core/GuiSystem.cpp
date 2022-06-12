#include "Core/Include/GuiSystem.h"
#include "Editor/Editor.h"

void GuiSystem::RenderGui() {
    Docking();
    SectionBar();
}

void GuiSystem::Docking() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (optFullscreen) {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else {
        dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) {
        window_flags |= ImGuiWindowFlags_NoBackground;
    }

    if (!optPadding) {
       ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    }

    ImGui::Begin("DockSpace", nullptr, window_flags);
    if (!optPadding) {
        ImGui::PopStyleVar();
    }

    if (optFullscreen) {
        ImGui::PopStyleVar(2);
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    MenuBar();

    ImGui::End();
}

void GuiSystem::MenuBar() {
    if (ImGui::BeginMenuBar()) {

        MenuFile();
        MenuEdit();

        ImGui::EndMenuBar();
    }
}

void GuiSystem::MenuFile() {
    if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("New", nullptr, &isNewSelected)) {

        }

        if (ImGui::MenuItem("Open", nullptr, &isOpenSelected)) {

        }
        ImGui::Separator();

        if (ImGui::MenuItem("Open Recent", nullptr, &isOpenRecentSelected)) {

        }
        ImGui::Separator();

        if (ImGui::MenuItem("Save", nullptr, &isSaveSelected)) {

        }

        if (ImGui::MenuItem("Save All", nullptr, &isSaveAllSelected)) {

        }
        ImGui::Separator();

        if (ImGui::MenuItem("Exit", nullptr, &isExitSelected)) {

        }

        ImGui::EndMenu();
    }
}

void GuiSystem::MenuEdit() {
    if (ImGui::BeginMenu("Edit")) {


        ImGui::EndMenu();
    }
}

void GuiSystem::AlignButtons() {
    ImGuiStyle& style = ImGui::GetStyle();
    float width = 0.0f;
    width += ImGui::CalcTextSize("Media").x;
    width += style.ItemSpacing.x;
    width += 1000.0f;
    width += style.ItemSpacing.x;
    width += ImGui::CalcTextSize("Deliver").x;

    float avail = ImGui::GetContentRegionAvail().x;
    float off = (avail - width) * 0.5f;
    if (off > 0.0f) {
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
    }
}

void GuiSystem::SectionBar() {
    ImGuiWindowFlags sectionBarFlags = 0;
    sectionBarFlags |= ImGuiWindowFlags_NoDecoration;
    sectionBarFlags |= ImGuiWindowFlags_NoMove;
    sectionBarFlags |= ImGuiWindowFlags_NoScrollWithMouse;

    ImGui::Begin("##SectionBar", nullptr, sectionBarFlags);
    AlignButtons();

    if (ImGui::Button("Media", ImVec2(150.0f, 0.0f))) {
        legacyWindows = MEDIA;
    }
    ImGui::SameLine();

    if (ImGui::Button("Texture", ImVec2(150.0f, 0.0f))) {
        legacyWindows = TEXTURE;
    }
    ImGui::SameLine();

    if (ImGui::Button("Colour", ImVec2(150.0f, 0.0f))) {
        legacyWindows = COLOUR;
    }
    ImGui::SameLine();

    if (ImGui::Button("Editor", ImVec2(150.0f, 0.0f))) {
        legacyWindows = EDIT;
    }
    ImGui::SameLine();

    if (ImGui::Button("TimeLine", ImVec2(150.0f, 0.0f))) {
        legacyWindows = TIMELINE;
    }
    ImGui::SameLine();

    if (ImGui::Button("Audio", ImVec2(150.0f, 0.0f))) {
        legacyWindows = AUDIO;
    }
    ImGui::SameLine();

    if (ImGui::Button("Deliver", ImVec2(150.0f, 0.0f))) {
        legacyWindows = DELIVER;
    }

    ImGui::End();

    Editor editor;

    switch (legacyWindows) {
    case MEDIA:
        break;
    
    case TEXTURE:
        break;
    
    case COLOUR:
        break;

    case EDIT:
        editor.RenderEditor();
        break;

    case TIMELINE:
        break;

    case AUDIO:
        break;

    case DELIVER:
        break;

    default:
        break;
    }
    
}


