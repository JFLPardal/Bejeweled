#include "Game.h"

#include "gameEntities/ClickHandler.h"
#include "EventHandler.h"
#include "gameEntities/Grid.h"
#include "TextureManager.h"

SDL_Renderer* Game::pRenderer = nullptr;
bool Game::isRunning;

Game::Game()
	:pEventHandler(new EventHandler())
{
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		printf( "SDL_Init did not initialize properly." );
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
	pClickHandler = new ClickHandler();
}

void Game::HandleEvents()
{
	pEventHandler->CheckForEvents(*pGrid, *pClickHandler);
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
	delete pClickHandler;
	SDL_Quit(); // shut sdl subsystems
}

void Game::RenderDrawing()
{
	SDL_RenderPresent(pRenderer);
}

void Game::QuitGame()
{
	isRunning = false;
}

bool Game::TryCreateWindow(const char* title, int initialWindowX, int initialWindowY, int windowWidth, int windowHeight)
{
	pWindow = SDL_CreateWindow(title, initialWindowX, initialWindowY, windowWidth, windowHeight, 0);
	if (!pWindow)
	{
		printf("Game window was not created.");
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
		printf("Game renderer was not created.");
		SetIsRunning(false);
		return false;
	}
	return true;
}

Game::~Game()
{
}
