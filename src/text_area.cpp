#include "../inc/pattern.hpp"

Text_area::Text_area(Vector2 n_pos, std::string n_name, int n_width, int n_height, Color n_color) : pos(n_pos), name(n_name), width(n_width), height(n_height), color(n_color), scroll(0)
{
    std::cout << scroll << std::endl;
	name_width = MeasureText(name.c_str(), width);
}

Text_area::~Text_area()
{
    std::cout << "destructor text_area called" << std::endl;
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

void    Text_area::CREATE_Displayed_Text()
{
    displayed_text.clear();
    max_char_per_line = width / char_size - 2;
    int n_line(1);
    for (size_t i = 0; i < text.length(); i++, n_line++)
    {
        displayed_text += text[i];
        if (n_line == max_char_per_line)
        {
            displayed_text += '\n';
            n_line = 0;
        }
    }
}

int    Text_area::Input_text()
{
    //MeasureText("a", (width * height) * 0.001f) > height
    SCROLL(GetMouseWheelMove());
    int key = GetKeyPressed();
    if ((key < 48 || key > 122) && (key != KEY_BACKSPACE && key != KEY_ENTER))
        return(0);
    if (key == KEY_BACKSPACE && !text.empty())
        text.pop_back();
    else if (key == KEY_ENTER)
        return (1);
    else if (key != KEY_BACKSPACE)
    {
        if (IsKeyDown(KEY_LEFT_SHIFT)) 
            text += (char)key;
        else
            text += (char)(key + 32);
    }
    CREATE_Displayed_Text();
    std::cout << text << std::endl;
    return (0);
}

void    Text_area::DISPLAY_Area()
{
    char_size = MeasureText("a", (width * height) * 0.001f);
    DrawRectangle(pos.x, pos.y, width, height, WHITE);
    if (text.empty())
            DrawText(name.c_str(), pos.x + width / 2 - MeasureText(name.c_str(), (width * height) * 0.001f) / 2,
                pos.y + height / 2 - MeasureText("a", (width * height) * 0.001f), (width * height) * 0.001f, BLACK);
    else
    {
        std::istringstream flux(displayed_text);
        std::string line;
        int max_line_displayed = height / (char_size * 1.5) - 1;
        for (int i = 0; scroll > i; i++)// passer leslignes scroller
            std::getline(flux, line);
        for (int i = 0; std::getline(flux, line) && max_line_displayed > i; i++) 
        {
            DrawText(line.c_str(), pos.x, pos.y + (char_size * 1.5)* i, (width * height) * 0.001f, BLACK);
        }
    }
}
