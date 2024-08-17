#ifndef SEARCHER_HPP
# define SEARCHER_HPP

#include "pattern_saver.hpp"

class Pattern_saver;

class Searcher
{
    private:
        Button  saver;
        
        Pattern_saver *pattern_saver;
        std::vector<Pattern>    pattern;
        int id_open_text;
        int n_folder;
        int scroll;
        int pattern_height;
        int width;
        int height;
    public:
        //Searcher(){}
        Searcher(Pattern_saver *p_pattern_saver);
        ~Searcher();

        void    CLICK(Vector2 mouse_pos);
        void    DISPLAY();
        void    UPDATE_Searcher();
        int     TEXT_Inp_Open();
        void    TEXT_Inp();
};

#endif
