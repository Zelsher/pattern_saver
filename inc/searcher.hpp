#ifndef SEARCHER_HPP
# define SEARCHER_HPP

#include "pattern.hpp"

class Pattern;

class Searcher
{
    private:
        Button  saver;
        
        Pattern *pattern;
        int id_open_text;
    public:
        //Searcher(){}
        Searcher(Pattern *p_pattern);
        ~Searcher();

        void    CLICK(Vector2 mouse_pos);
        void    DISPLAY();
        int     TEXT_Inp_Open();
        void    TEXT_Inp();
};

#endif
