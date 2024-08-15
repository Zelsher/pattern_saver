#include "../inc/pattern.hpp"

Searcher::Searcher(Pattern *p_pattern) : saver(Vector2{0, 0}, "saver", 50, 50, BLUE), pattern(p_pattern)
{

}

Searcher::~Searcher()
{
    std::cout << "destructor called" << std::endl;
}

void   Searcher::CLICK(Vector2 mouse_pos)
{
    if (saver.IS_Clicked(mouse_pos))
    {
        std::cout << "saver clicked" << std::endl;
        pattern->CHANGE_Mod(SAVER); 
    }
}

void    Searcher::DISPLAY()
{
    DrawRectangle(saver.POS().x, saver.POS().y, saver.WIDTH(), saver.HEIGHT(), saver.COLOR());
    DrawText(saver.NAME().c_str(), saver.POS().x, saver.POS().y + saver.HEIGHT() / 2, saver.NAME_Width(), WHITE);
}
