#ifndef PATTERN_HPP
# define PATTERN_HPP

#include "pattern_saver.hpp"

class Button;

class Pattern 
{
	private:
		Vector2 pos;
		std::string name;
		std::string path;
		std::string wav_file;
		std::string description_file;
		int     width;
		int     height;
		int     char_size;
		Button  play;
		Color   color;

		Picture_preview	img_preview;
	public:
		Pattern(Vector2 pos, std::string n_name, std::string n_path, int n_width, int n_height);
		~Pattern();
		int		CLICK(Vector2 n_pos);
		void    DISPLAY();
		void    PLAY_Wav();
		void	DISPLAY_Full_Image(int win_width, int win_height) { img_preview.DISPLAY_Full_Image(win_width, win_height); };

		void	RESIZE(int n_width, int n_height);
		void	MOOVE(int n_posx, int n_posy);
};

#endif