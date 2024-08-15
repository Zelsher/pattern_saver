#include "../inc/pattern.hpp"

Text_area::Text_area(Vector2 n_pos, std::string n_name, int n_width, int n_height, Color n_color) : pos(n_pos), name(n_name), width(n_width), height(n_height), color(n_color)
{
	name_width = MeasureText(name.c_str(), width);
}

Text_area::~Text_area()
{
    std::cout << "destructor called" << std::endl;
}

int    Text_area::IS_Clicked(Vector2 click_pos)
{
    if (click_pos.x > pos.x && click_pos.x < pos.x + width
        && click_pos.y > pos.y && click_pos.y < pos.y + height)
        return (1);
    return (0);
}

int     Text_area::CLICK_Outside_Text_Area()
{
    if (!IsMouseButtonPressed(0))
        return (0);
    Vector2 mouse_pos = GetMousePosition();
    if (!IS_Clicked(mouse_pos))
        return (1);
    return (0);
}

int    Text_area::Input_text(int key)
{
    if (key == 0)
        return(0);
    if (key == KEY_ENTER)
        return (1);
    text += key;
    std::cout << text << std::endl;
    return (0);
}

void    Text_area::DISPLAY_Area()
{
    DrawRectangle(pos.x, pos.y, width, height, color);
    if (!text.empty())
        DrawText(name.c_str(), pos.x, pos.y + height / 2, name_width, BLACK);
    else
        DrawText(text.c_str(), pos.x, pos.y + height / 2, MeasureText(text.c_str(), width), BLACK);
}