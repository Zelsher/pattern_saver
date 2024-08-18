#include "../inc/pattern_saver.hpp"

void	DRAW_Outline(Vector2 pos, int width, int height)
{
	DrawRectangle(pos.x, pos.y, width, 1, BLACK);
	DrawRectangle(pos.x, pos.y, 1, height, BLACK);

	DrawRectangle(pos.x, pos.y + height, width, height / 100, BLACK);
	DrawRectangle(pos.x + width, pos.y, height / 100, height + width / 100, BLACK);
}