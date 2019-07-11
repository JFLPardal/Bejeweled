#pragma once
#include "preCompiledHeader.h"

#include "EventHandler.h"
#include "TextureManager.h"
#include "gameEntities/Grid.h"

// game window properties
static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 768;
static const char* WINDOW_TITLE = "Bejeweled by Joao Pardal";

class Game
{
public:
	Game();
	~Game();

	void Init();

	void HandleEvents();
	void Update();
	void Draw();
	void Clean();

	inline bool IsRunning() const { return isRunning; }
	static SDL_Renderer* pRenderer;
private:
	bool isRunning;
	SDL_Window* pWindow = nullptr;
	EventHandler* pEventHandler= nullptr;
	
	Grid* pGrid = nullptr;
	TextureManager* textureManager = nullptr;

	void SetIsRunning(bool runningState) { isRunning = runningState; }
	
	bool TryCreateWindow(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight);
	bool TryCreateRenderer();
};


