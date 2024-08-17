#ifndef SAVER_HPP
# define SAVER_HPP

#include "pattern_saver.hpp"

class Pattern_saver;

class Saver
{
    private:
        Button                  searcher;
        Button                  save;
        std::vector<Text_area>  text_area;
        Pattern_saver     *pattern;
        
        int area_click;
    public:
        //Saver() {};
        Saver(Pattern_saver *p_pattern);
        ~Saver();

        void    CLICK(Vector2 mouse_pos);
        void    DISPLAY();
        int     TEXT_Inp_Open();
        void    TEXT_Inp();
        void    save_pattern();
};

#endif
