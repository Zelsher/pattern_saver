#ifndef PATTERN_HPP
# define PATTERN_HPP

# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <fstream>

# include "raylib/src/raylib.h"
# include "pattern.hpp"
# include "button.hpp"
# include "text_area.hpp"
# include "saver.hpp"
# include "searcher.hpp"

#define WAV_PATH "test"
#define SAVE_PATH "test"

#define SAVER 1
#define SEARCHER 2

class Pattern 
{
    private:
        int         mod;
        Saver       saver;
        Searcher    searcher;
        int         width;
        int         height;
        Vector2     mouse_pos;
    public:
        Pattern();
        ~Pattern();

        void    DISPLAY();
        void    HANDLE_Input();
        void    DISPLAY_Saver();
        void    DISPLAY_Searcher();

        void    CHANGE_Mod(int n_mod) { mod = n_mod; }
};

#endif