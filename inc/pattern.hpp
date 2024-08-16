#ifndef PATTERN_HPP
# define PATTERN_HPP

# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include <iomanip>
#include <filesystem>
# include <cmath>
# include <fstream>

# include "raylib.h"
# include "pattern.hpp"
# include "button.hpp"
# include "text_area.hpp"
# include "saver.hpp"
# include "searcher.hpp"

#define WAV_PATH "test"
#define SAVE_PATH "test"

#define SAVER 1
#define SEARCHER 2

#define BASE_WIDTH 1000
#define BASE_HEIGHT 300

#define SAVE_FOLDER "saved_pattern/"
#define WAV_FOLDER "wav_folder/"

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

        void    CHANGE_Mod(int n_mod) { mod = n_mod; }//penser a fermer toutes les zones de texte
        int     WIDTH() { return width; }
        int     HEIGHT() { return height;}
};

#endif