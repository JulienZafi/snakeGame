#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

enum class DIRECTION{ UP = 0, DOWN, LEFT, RIGHT, UNKNOWN };
enum class POSITION{ FIRST = 0, MID, LAST, UNKNOWN };

struct SnakeBlock
{
	SnakeBlock() : direction(DIRECTION::UNKNOWN), x(0), y(0), position(POSITION::UNKNOWN){};
	SnakeBlock(SnakeBlock const &snakeTemplate) :
		direction(snakeTemplate.direction), x(snakeTemplate.x), y(snakeTemplate.y), position(snakeTemplate.position), carac(snakeTemplate.carac) {};
	SnakeBlock(DIRECTION dir, unsigned int xpos, unsigned int ypos, POSITION pos, wchar_t snakeCarac) :
		direction(dir), x(xpos), y(ypos), position(pos), carac(snakeCarac) {};

	/*Motion direction*/
	DIRECTION direction;

	/*Bloc location*/
	unsigned int x;
	unsigned int y;

	/*Bloc position in entire snake*/
	POSITION position;

	/*Representation on console output*/
	wchar_t carac;
};

#endif