#include "TextureManager.h"

#include "Game.h"

SDL_Rect TextureManager::destinationRect;
SDL_Surface* TextureManager::pSurfaceWithImage = nullptr;
SDL_Texture* TextureManager::pSprite = nullptr;
std::map<StoneType, SDL_Texture*> TextureManager::stoneSprites;

TextureManager::TextureManager()
{
	destinationRect.x = destinationRect.y = 0;
	destinationRect.w = STONE_WIDTH;
	destinationRect.h = STONE_HEIGHT;
	std::cout << std::endl << "stoneSprites size: " << stoneSprites.size();
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
	stoneSprites.emplace(StoneType::diamond, pSprite);
	SDL_FreeSurface(pSurfaceWithImage);

	std::cout << std::endl << "stoneSprites size: " << stoneSprites.size();
	return true;
}

SDL_Texture* TextureManager::GetStoneTexture(StoneType stoneType)
{
	return pSprite;
}

void TextureManager::Draw(const Stone* stone)
{
	Vector2 stonePosition = stone->GetPosition();
	destinationRect.x = stonePosition.X();
	destinationRect.y = stonePosition.Y();

	SDL_RenderCopy(Game::pRenderer, stoneSprites[stone->GetStoneType()], NULL, &destinationRect);
}

TextureManager::~TextureManager()
{
	SDL_DestroyTexture(pSprite);
}
