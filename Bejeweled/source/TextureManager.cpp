#include "TextureManager.h"

#include "Game.h"
#include "gameEntities/GridConstants.h"

SDL_Rect TextureManager::destinationRect;
SDL_Surface* TextureManager::pSurfaceWithImage = nullptr;
SDL_Texture* TextureManager::pSprite = nullptr;
std::map<StoneType, SDL_Texture*> TextureManager::stoneSprites;

TextureManager::TextureManager()
{
	destinationRect.x = destinationRect.y = 0;
	destinationRect.w = STONE_CONSTANTS::STONE_WIDTH;
	destinationRect.h = STONE_CONSTANTS::STONE_HEIGHT;

	LoadAllTextures();
}

void TextureManager::LoadAllTextures()
{
	LoadTexture(StoneType::diamond, textureNames::stones::diamond.c_str());
	LoadTexture(StoneType::flame, textureNames::stones::flame.c_str());
	LoadTexture(StoneType::moon, textureNames::stones::moon.c_str());
	LoadTexture(StoneType::skull, textureNames::stones::skull.c_str());
	LoadTexture(StoneType::star, textureNames::stones::star.c_str());
	SDL_FreeSurface(pSurfaceWithImage);
}

void TextureManager::LoadTexture(StoneType stoneType, const char * spritePath)
{
	pSurfaceWithImage = IMG_Load(spritePath);
	if (pSurfaceWithImage == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", spritePath, SDL_GetError());
	}
	pSprite = SDL_CreateTextureFromSurface(Game::pRenderer, pSurfaceWithImage);
	if(pSprite == NULL)	printf("Unable to CREATE TEXTURE %s! SDL Error: %s\n", spritePath, SDL_GetError());
	stoneSprites.emplace(stoneType, pSprite);
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
