#pragma once

#include "preCompiledHeader.h"

namespace textureNames
{
	static std::string STONES_DIRECTORY_PATH = "assets/sprites/stones/";
	static std::string BACKGROUNDS_DIRECTORY_PATH = "assets/sprites/";
	namespace stones
	{
		static const std::string tile_01 = STONES_DIRECTORY_PATH + "diamond.png";
		static const std::string tile_02 = STONES_DIRECTORY_PATH + "flame.png";
		static const std::string tile_03 = STONES_DIRECTORY_PATH + "moon.png";
		static const std::string tile_04 = STONES_DIRECTORY_PATH + "skull.png";
		static const std::string tile_05 = STONES_DIRECTORY_PATH + "star.png";
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

private:
	static SDL_Surface* pSurfaceWithImage;
	static SDL_Texture* pSprite;

	// map <enum StoneType, SDL_Texture* pSprite> stones;
};

