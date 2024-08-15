#ifndef SEARCHER_HPP
# define SEARCHER_HPP

#include "pattern.hpp"

class Pattern;

class Searcher
{
    private:
        Button  saver;

        Pattern *pattern;
    public:
        //Searcher(){}
        Searcher(Pattern *p_pattern);
        ~Searcher();

        void    CLICK(Vector2 mouse_pos);
        void    DISPLAY();
};

#endif
