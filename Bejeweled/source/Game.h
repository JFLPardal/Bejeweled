#pragma once

#include "preCompiledHeader.h"

#include "gameEntities/GridConstants.h"

class EventHandler;
class Grid;
class TextureManager;
class ClickHandler;

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
	TextureManager* pTextureManager = nullptr;
	ClickHandler* pClickHandler = nullptr;

	void SetIsRunning(bool runningState) { isRunning = runningState; }
	
	bool TryCreateWindow(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight);
	bool TryCreateRenderer();
};


