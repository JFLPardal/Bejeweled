#include "Game.h"

#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		std::cout << "SDL_Init did not initialize properly." << std::endl;
		return;
	}

	if (!TryCreateWindow(title, initialWindowX, initialWindowY, windowWidth, windowHeight))
	{
		return;
	}
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); // this way we can control the frame rate manually
	if (!pRenderer)
	{
		std::cout << "Game renderer was not created." << std::endl;
		return;
	}
	SDL_SetRenderDrawColor(pRenderer, 50, 200, 100, 255);
	SetIsRunning(true);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		SetIsRunning(false);
	}
}

void Game::Update()
{
	std::cout << "frame" << std::endl;
}

void Game::Draw()
{
	SDL_RenderClear(pRenderer);

	SDL_RenderPresent(pRenderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
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

