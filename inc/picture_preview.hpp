#ifndef PICTURE_PREVIEW_HPP
# define PICTURE_PREVIEW_HPP

#include "pattern_saver.hpp"

class Picture_preview 
{
	private:
		int			valid;
		Vector2		pos;
		int         width;
		int         height;
		Image		picture;
		Texture2D	preview;

	public:
		Picture_preview(std::string path, Vector2 n_pos, int width, int height);
		~Picture_preview();

		void	DISPLAY();
		void	DISPLAY_Full_Image(int win_width, int win_height);
		void	RESIZE(int n_width, int n_height);
		void	MOOVE(int n_posx, int n_posy);

		int     IS_Clicked(Vector2 click_pos);
};

#endif