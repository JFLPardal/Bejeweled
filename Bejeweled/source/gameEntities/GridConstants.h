#pragma once

namespace WINDOW_CONSTANTS
{
	static const int WINDOW_WIDTH = 1024;
	static const int WINDOW_HEIGHT = 768;
	static const char* WINDOW_TITLE = "Bejeweled by Joao Pardal";
}
namespace WC = WINDOW_CONSTANTS;

namespace STONE_CONSTANTS
{
	static const int STONE_WIDTH = 70;
	static const int STONE_HEIGHT = 70;
}
namespace SC = STONE_CONSTANTS;

namespace GRID_CONSTANTS 
{
	using namespace WINDOW_CONSTANTS;
	using namespace STONE_CONSTANTS;
	// grid dimensions
	static const int GRID_WIDTH = 8;
	static const int GRID_HEIGHT = GRID_WIDTH;
	// padding between stones, pixels to the right and bottom of each stone that should not be occupied by other stones
	static const int GRID_HORIZONTAL_PADDING = 2;
	static const int GRID_VERTICAL_PADDING = 2;
	// size in pixels occupied by each stone
	static const int TOTAL_STONE_WIDTH = STONE_WIDTH + GRID_VERTICAL_PADDING;
	static const int TOTAL_STONE_HEIGHT = STONE_HEIGHT + GRID_HORIZONTAL_PADDING;
	// size of the entire grid
	static const int GRID_WIDTH_IN_PIXELS = GRID_WIDTH * TOTAL_STONE_WIDTH;
	static const int GRID_HEIGHT_IN_PIXELS = GRID_HEIGHT * TOTAL_STONE_HEIGHT;
	// grid's origin
	static const int INITIAL_X = (int)WINDOW_WIDTH / 2 - (int)GRID_WIDTH_IN_PIXELS / 2;
	static const int INITIAL_Y = (int)WINDOW_HEIGHT / 2 - (int)GRID_HEIGHT_IN_PIXELS / 2;
};
namespace GC = GRID_CONSTANTS;
