#include "TextureManager.h"

#include "Game.h"

SDL_Surface* TextureManager::pSurfaceWithImage = nullptr;
SDL_Texture* TextureManager::pSprite = nullptr;

TextureManager::TextureManager()
{
}

bool TextureManager::LoadTexture(const char * spritePath)
{
	pSurfaceWithImage = IMG_Load(spritePath);
	if (pSurfaceWithImage == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", spritePath, SDL_GetError());
		return false;
	}
	pSprite = SDL_CreateTextureFromSurface(Game::pRenderer, pSurfaceWithImage);
	return true;
}

TextureManager::~TextureManager()
{
	SDL_FreeSurface(pSurfaceWithImage);
	SDL_DestroyTexture(pSprite);
}
