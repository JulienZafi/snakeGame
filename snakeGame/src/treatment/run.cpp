
#include "classes/GameEngine.hpp"
#include "classes/Snake.hpp"

#define WIDTH 120
#define HEIGHT 40

wchar_t const defaultFoodCarac{ L'o' };
wchar_t const defaultSnakeCarac{ L'O' };
UINT const snakeInitialSize{ 10 };
UINT const defaultXpos{ 55 };
UINT const defaultYpos{ 20 };
DIRECTION const defaultDir{ DIRECTION::LEFT };

int main()
{
	GameEngine *game{ &GameEngine::GetInstance() };
	
	game->CreateConsole(WIDTH, HEIGHT);
	game->Start(defaultFoodCarac, defaultSnakeCarac, snakeInitialSize, defaultXpos, defaultYpos, defaultDir);

	return 0;
}