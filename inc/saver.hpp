#ifndef SAVER_HPP
# define SAVER_HPP

#include "pattern.hpp"

class Pattern;

class Saver
{
    private:
        Button      searcher;
        Button      save;
        Text_area   name_area;
        int         name_area_click;
        Pattern     *pattern;
    public:
        //Saver() {};
        Saver(Pattern *p_pattern);
        ~Saver();

        void    CLICK(Vector2 mouse_pos);
        void    DISPLAY();
};

#endif
