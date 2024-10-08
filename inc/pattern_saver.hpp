#ifndef PATTERN_SAVER_HPP
# define PATTERN_SAVER_HPP

# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include <iomanip>
# include <filesystem>
# include <cmath>
# include <fstream>
# include <sstream>

# include "raylib.h"
# include "functions.hpp"
# include "picture_preview.hpp"
# include "button.hpp"
# include "text_area.hpp"
# include "pattern.hpp"
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

#define	IMG_PREVIEW 1
#define DESCRIPTION_PREVIEW 2

class Pattern_saver 
{
	private:
		int         mod;
		Saver       saver;
		Searcher    searcher;
		int         width;
		int         height;
		Vector2     mouse_pos;
	public:
		Pattern_saver();
		~Pattern_saver();

		void    DISPLAY();
		void    HANDLE_Input();
		void    RESIZE_Pattern_Saver();
	
		void    CHANGE_Mod(int n_mod) { if (n_mod == SEARCHER) {searcher.UPDATE();} mod = n_mod; }//penser a fermer toutes les zones de texte
		int     WIDTH() { return width; }
		int     HEIGHT() { return height;}
};

#endif