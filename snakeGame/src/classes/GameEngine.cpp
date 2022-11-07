
#include "classes/GameEngine.hpp"
#include "functions/functions.hpp"

GameEngine& GameEngine::GetInstance()
{
	if (!_instance_)
	{
		_instance_ = new GameEngine;
	}
	else{}

	return (*_instance_);
}

GameEngine::~GameEngine()
{
	if (_instance_)
	{
		delete _instance_;
		_instance_ = nullptr;
	}
	else{}

	if (m_screen)
	{
		delete[] m_screen;
		m_screen = nullptr;
	}
	else{}
}

void GameEngine::CreateConsole(UINT screenWidth, UINT screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	m_screen = new wchar_t[screenWidth * screenHeight];
	for (UINT i{ 0 }; i < (m_screenWidth * m_screenHeight); ++i)
	{
		m_screen[i] = L' ';
	}

	m_console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(m_console);
	m_bytesWritten = 0;
}

void GameEngine::UpdateScreen(UINT pos, wchar_t const output)
{
	m_screen[pos] = output;
}

void GameEngine::WriteToConsole()
{
	WriteConsoleOutputCharacter(m_console, m_screen, m_screenWidth * m_screenHeight, { 0,0 }, &m_bytesWritten);
}

void GameEngine::Start(wchar_t const defaultFoodCarac, wchar_t const defaultSnakeCarac, UINT const initialSize, UINT const initialXpos, UINT const initialYpos, DIRECTION const defaultDir)
{
	Snake *snake{ &Snake::GetInstance() };
	SnakeBlock snakeBlock(defaultDir, initialXpos, initialYpos, POSITION::UNKNOWN, defaultSnakeCarac);
	snake->Initialize(initialSize, snakeBlock);

	while (snake->IsAlive())
	{
		PrintSnakeBlocks(snake->GetSnakeBlocks());
		PrintFood(defaultFoodCarac);
		snake->Move();
		
		WriteToConsole();
	}
}

void GameEngine::PrintFood(wchar_t const carac)
{
	unsigned int randomPos{ randomPosition(0, (m_screenWidth * m_screenHeight)) };

	UpdateScreen(randomPos, carac);
}

void GameEngine::PrintSnakeBlocks(std::vector <SnakeBlock> const& snakeBlocks)
{
	// Clear screen
	for (unsigned int i{ 0 }; i < (m_screenWidth * m_screenHeight); ++i)
	{
		UpdateScreen(i, L' ');
	}

	for (auto const &block : snakeBlocks)
	{
		UINT pos{ block.x + block.y * m_screenWidth };
		UpdateScreen(pos, block.carac);
	}
}

DIRECTION GameEngine::GetUserInput()
{
	if (GetAsyncKeyState(VK_UP))
	{

	}
	else{}
}