#pragma once

#include "preCompiledHeader.h"

#include "gameEntities/Stone.h"

namespace textureNames
{
	static std::string STONES_DIRECTORY_PATH = "assets/sprites/stones/";
	static std::string BACKGROUNDS_DIRECTORY_PATH = "assets/sprites/";
	namespace stones
	{
		static const std::string diamond = STONES_DIRECTORY_PATH + "diamond.png";
		static const std::string flame = STONES_DIRECTORY_PATH + "flame.png";
		static const std::string moon = STONES_DIRECTORY_PATH + "moon.png";
		static const std::string skull = STONES_DIRECTORY_PATH + "skull.png";
		static const std::string star = STONES_DIRECTORY_PATH + "star.png";
	}
	namespace backgrounds
	{
		static const std::string background_01 = BACKGROUNDS_DIRECTORY_PATH + "background_space.jpg";
	}
}

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static bool LoadTexture(const char* spritePath);
	static SDL_Texture* GetStoneTexture(StoneType stoneType);
	static void Draw(const Stone* stoneToDraw);

private:
	static SDL_Rect destinationRect;
	static SDL_Surface* pSurfaceWithImage;
	static SDL_Texture* pSprite;
	static std::map<StoneType, SDL_Texture*> stoneSprites;
};

