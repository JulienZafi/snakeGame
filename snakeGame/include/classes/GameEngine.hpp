#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "classes/Snake.hpp"

#include <memory>

#include <Windows.h>

class GameEngine
{
public:
	static GameEngine& GetInstance();

	GameEngine(GameEngine const& gameEngine) = delete;
	GameEngine& operator=(const GameEngine) = delete;

	void CreateConsole(UINT screenWidth, UINT screenHeight);
	DIRECTION GetUserInput();
	void PrintFood(wchar_t const carac);
	void PrintSnakeBlocks(std::vector <SnakeBlock> const& snakeBlocks);
	void Start(wchar_t const defaultFoodCarac, wchar_t const defaultSnakeCarac, UINT const initialSize, UINT const initialXpos, UINT const initialYpos, DIRECTION const defaultDir);
	void UpdateScreen(UINT pos, wchar_t const output);
	void WriteToConsole();

private:
	inline static GameEngine *_instance_{ nullptr };
	GameEngine() = default;
	 virtual ~GameEngine();

	 wchar_t *m_screen;
	 UINT m_screenWidth;
	 UINT m_screenHeight;
	 HANDLE m_console;
	 DWORD m_bytesWritten;
};

#endif