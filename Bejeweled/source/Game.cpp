#include "Game.h"

#include <iostream>

SDL_Renderer* Game::pRenderer = nullptr;

Game::Game()
	:pEventHandler(new EventHandler()), textureManager(new TextureManager())
{
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		std::cout << "SDL_Init did not initialize properly." << std::endl;
		return;
	}

	if (!TryCreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT)) { return;}
	if (!TryCreateRenderer()) { return; }

	SDL_SetRenderDrawColor(pRenderer, 50, 200, 100, 255);
	SetIsRunning(true);

	// GRID
	pGrid = new Grid();
	std::cout << *pGrid;


	std::cout << "\n"<< pGrid->GetStoneInPosition(Vector2(2, 2)).GetPosition().ToString();
	std::cout << "\n"<< pGrid->GetStoneInPosition(Vector2(7, 7)).GetPosition().ToString();
	std::cout << "\n"<< pGrid->GetStoneInPosition(Vector2(3, 6)).GetPosition().ToString();

	// LOAD TEXTURES
	if (!textureManager->LoadTexture(textureNames::stones::diamond.c_str()))
	{
		std::cout << "texture could not be lodaded";
	}
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
	pEventHandler->CheckForEvents();
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
	delete textureManager;
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
