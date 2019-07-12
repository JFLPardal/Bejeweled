#include "Game.h"

#include <iostream>

SDL_Renderer* Game::pRenderer = nullptr;

Game::Game()
	:pEventHandler(new EventHandler())
{
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		std::cout << "SDL_Init did not initialize properly." << std::endl;
		return;
	}

	if (!TryCreateWindow(WINDOW_CONSTANTS::WINDOW_TITLE, 
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
						WC::WINDOW_WIDTH, WC::WINDOW_HEIGHT)) { return;}
	if (!TryCreateRenderer()) { return; }
	pTextureManager = new TextureManager();

	SDL_SetRenderDrawColor(pRenderer, 50, 200, 100, 255);
	SetIsRunning(true);

	pGrid = new Grid();
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		SetIsRunning(false);
	}
	// TODO: move the above to EventHandler class
	pEventHandler->CheckForEvents(*pGrid);
}

void Game::Update()
{
}

void Game::Draw()
{
	SDL_RenderClear(pRenderer);
	pGrid->Draw();
	SDL_RenderPresent(pRenderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	delete pEventHandler;
	delete pTextureManager;
	delete pGrid;
	SDL_Quit(); // shut sdl subsystems
}

bool Game::TryCreateWindow(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight)
{
	pWindow = SDL_CreateWindow(title, initialWindowX, initialWindowY, windowWidth, windowHeight, 0);
	if (!pWindow)
	{
		std::cout << "Game window was not created." << std::endl;
		SetIsRunning(false);
		return false;
	}
	return true;
}

bool Game::TryCreateRenderer()
{
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); // this way we can control the frame rate manually
	if (!pRenderer)
	{
		std::cout << "Game renderer was not created." << std::endl;
		SetIsRunning(false);
		return false;
	}
	return true;
}

Game::~Game()
{
}
