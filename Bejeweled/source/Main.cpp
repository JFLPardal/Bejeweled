#include "preCompiledHeader.h"

#include "Game.h"

// frame rate
const int INTENDED_FPS = 60;
const int INTENDED_FRAME_DURATION = 1000 / INTENDED_FPS;

void EnforceFrameRate(Uint32 const frameStart);

int SDL_main(int argc, char *argv[])
{
	std::unique_ptr<Game> game(new Game());
	game->Init();
	
	Uint32 frameStart;

	while (game->IsRunning())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Draw();

		EnforceFrameRate(frameStart);
	}

	game->Clean();
	return 0;
}

void EnforceFrameRate(Uint32 const frameStart)
{
	Uint32 frameDuration;
	frameDuration = SDL_GetTicks() - frameStart;
	if (INTENDED_FRAME_DURATION > frameDuration)
	{
		SDL_Delay(INTENDED_FRAME_DURATION - frameDuration);
	}
}

