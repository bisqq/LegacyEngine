#pragma once

#ifndef EDITOR
#define EDITOR

struct Editor {
	Editor();
	~Editor();

	void RenderEditor();
	void Viewport();
	void ContentBrowser();
	void ToolBar();
};

#endif // !EDITOR
