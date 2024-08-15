#include "../inc/pattern.hpp"

Saver::Saver(Pattern *p_pattern) : searcher(Vector2{0, 50}, "searcher", 50, 50, GREEN),
                                    save(Vector2{0, 0}, "save", 50, 50, BLUE),
                                    name_area(Vector2{50, 0}, "name", 100, 50, WHITE),
                                    name_area_click(0),
                                    pattern(p_pattern)
{
}

Saver::~Saver()
{
    std::cout << "destructor called" << std::endl;
}

void   Saver::CLICK(Vector2 mouse_pos)
{
    if (save.IS_Clicked(mouse_pos))
    {
        std::cout << "save clicked" << std::endl;
        name_area_click = 0;
    }
    else if (searcher.IS_Clicked(mouse_pos))
    {
        std::cout << "searcher clicked" << std::endl;
        pattern->CHANGE_Mod(SEARCHER);
        name_area_click = 0;
    }
    else if (name_area.IS_Clicked(mouse_pos))
        name_area_click = 1;
    if (name_area_click == 1)
    {
        std::cout << "text ouvert" << std::endl;
        if (name_area.Input_text(GetKeyPressed()))
            name_area_click = 0;
    }
    else
        std::cout << "text fermer" << std::endl;
}

void    Saver::DISPLAY()
{
    save.DISPLAY_Button();
    searcher.DISPLAY_Button();
    name_area.DISPLAY_Area();
}