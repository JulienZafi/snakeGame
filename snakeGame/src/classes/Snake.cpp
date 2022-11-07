
#include "classes/Snake.hpp"

#include <Windows.h>

Snake& Snake::GetInstance()
{
	if (!_instance_)
	{
		_instance_ = new Snake;
	}
	else{}

	return (*_instance_);
}

Snake::~Snake()
{
	if (_instance_)
	{
		delete _instance_;
		_instance_ = nullptr;
	}
	else{}
}

void Snake::Initialize(unsigned int const snakeSize, SnakeBlock snakeTemplate)
{
	m_speed = 1;
	m_isAlive = true;
	m_snakeBlocks.reserve(snakeSize);
	for (unsigned int i{ 0 }; i < snakeSize; ++i)
	{
		InitBlockPosition(snakeTemplate, i);
		m_snakeBlocks.emplace_back(SnakeBlock(snakeTemplate));
	}

	m_time = std::chrono::system_clock::now();
}

void Snake::InitBlockPosition(SnakeBlock &snakeTemplate, unsigned int index)
{
	if (index == 0)
	{
		snakeTemplate.position = POSITION::FIRST;
	}
	else if (index == std::size(m_snakeBlocks) - 1)
	{
		snakeTemplate.position = POSITION::LAST;
	}
	else
	{
		snakeTemplate.position = POSITION::MID;
	}

	DIRECTION dir{ snakeTemplate.direction };
	switch (dir)
	{
	case DIRECTION::UP:
		++snakeTemplate.y;
		break;
	case DIRECTION::DOWN:
		--snakeTemplate.y;
		break;
	case DIRECTION::LEFT:
		++snakeTemplate.x;
		break;
	case DIRECTION::RIGHT:
		--snakeTemplate.x;
		break;
	default:
		break;
	}
}

void Snake::SetBlockLocation(SnakeBlock& block)
{
	DIRECTION dir{ block.direction };
	switch (dir)
	{
	case DIRECTION::UP:
		--block.y;
		break;
	case DIRECTION::DOWN:
		++block.y;
		break;
	case DIRECTION::LEFT:
		--block.x;
		break;
	case DIRECTION::RIGHT:
		++block.x;
		break;
	default:
		break;
	}
}

bool Snake::IsAlive() const noexcept
{
	return m_isAlive;
}

void Snake::SetAliveState(bool isAlive)
{
	m_isAlive = isAlive;
}

std::vector <SnakeBlock> Snake::GetSnakeBlocks() const noexcept
{
	return m_snakeBlocks;
}

double Snake::ElapsedTime()
{
	auto currentTime{ std::chrono::system_clock::now() };
	std::chrono::duration<double> elapsedTime{ currentTime - m_time };

	return elapsedTime.count();
}

void Snake::Move()
{
	auto currentTime{ std::chrono::system_clock::now() };
	double elapsedTime{ ElapsedTime() };

	if (elapsedTime > m_speed)
	{
		m_time = currentTime;
		for (auto& block : m_snakeBlocks)
		{
			UpdateDirection(DIRECTION::LEFT);
			SetBlockLocation(block);
		}
	}
	else {}
}

void Snake::UpdateDirection(DIRECTION newDirection)
{
	if (std::size(m_snakeBlocks) > 0)
	{
		m_snakeBlocks[0].direction = newDirection;
	}
}