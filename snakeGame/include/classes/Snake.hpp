#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "structures/structures.hpp"

#include <chrono>
#include <vector>

class Snake
{
public:
	static Snake& GetInstance();

	Snake(Snake const& snake) = delete;
	Snake& operator=(const Snake) = delete;

	double ElapsedTime();
	std::vector <SnakeBlock> GetSnakeBlocks() const noexcept;
	void Initialize(unsigned int const snakeSize, SnakeBlock snakeTemplate);
	bool IsAlive() const noexcept;
	void Move();
	void SetAliveState(bool const isAlive);
	void InitBlockPosition(SnakeBlock &snakeTemplate, unsigned int index);
	void SetBlockLocation(SnakeBlock &block);
	void UpdateDirection(DIRECTION newDirection);

private:
	inline static Snake *_instance_{ nullptr };
	Snake() = default;
	~Snake();

	std::vector <SnakeBlock> m_snakeBlocks;
	bool m_isAlive;
	std::chrono::system_clock::time_point m_time;
	double m_speed;
};

#endif