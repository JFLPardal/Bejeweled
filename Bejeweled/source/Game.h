#pragma once
#include <SDL.h>
#include <memory>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight);

	void HandleEvents();
	void Update();
	void Draw();
	void Clean();

	inline bool IsRunning() const { return isRunning; }
private:
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;

	void SetIsRunning(bool runningState) { isRunning = runningState; }
	bool TryCreateWindow(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight);
	
};

