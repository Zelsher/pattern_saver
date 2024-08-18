#include "../inc/pattern_saver.hpp"

Button::Button(Vector2 n_pos, std::string n_name, int n_width, int n_height, Color n_color) : pos(n_pos), name(n_name), width(n_width), height(n_height), color(n_color)
{
	name_width = MeasureText(n_name.c_str(), width);
	//std::cout << "constuctor called on " << name  << ": [" << width << "|" << height << "]" << "(" << pos.x << "x" << pos.y << ")" << std::endl;
}

Button::~Button()
{
	//std::cout << "destructor called on " << name << std::endl;
} 

int    Button::IS_Clicked(Vector2 click_pos)
{
	if (click_pos.x > pos.x && click_pos.x < pos.x + width
		&& click_pos.y > pos.y && click_pos.y < pos.y + height)
		return (1);
	return (0);
}

void    Button::DISPLAY_Button()
{
	DrawRectangle(pos.x, pos.y, width, height, color);

	DRAW_Outline(pos, width, height);
	
	DrawText(name.c_str(), pos.x + width / 2 - MeasureText(name.c_str(), 
		(width * height) * 0.001f) / 2, pos.y + height / 2 - MeasureText("a", (width * height) * 0.001f), (width * height) * 0.001f, WHITE);
	//std::cout << name << " Display" << std::endl;
}

void    Button::MOOVE(int n_posx, int n_posy)
{
	pos.x = n_posx;
	pos.y = n_posy;
}

void    Button::RESIZE(int n_width, int n_height)
{
	width = n_width;
	height = n_height;
}
