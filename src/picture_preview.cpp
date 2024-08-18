#include "../inc/pattern_saver.hpp"

Picture_preview::Picture_preview(std::string n_path, Vector2 n_pos, int n_width, int n_height) : valid (1), path(n_path), pos(n_pos), width(n_width), height(n_height)
{
	picture = LoadImage(n_path.c_str());
	if (picture.width <= 0 || picture.height <= 0)
	{
		valid = 0;
		return;
	}
	Image temp = ImageCopy(picture);

	ImageResize(&temp, width, height);
	preview = LoadTextureFromImage(temp);
	UnloadImage(temp);
	if (preview.id == 0)
	{
		UnloadImage(picture);
		valid = 0;
	}
}

Picture_preview::~Picture_preview()
{
	if (valid)
	{
		UnloadImage(picture);
		UnloadTexture(preview);
	}
}

void	Picture_preview::DISPLAY()
{
	if (valid)
	{

		std::cout << pos.x << "x" << pos.y << std::endl;
		DrawTexture(preview, pos.x, pos.y, WHITE);
	}
}

void	Picture_preview::RESIZE(int n_width, int n_height)
{
	if (!valid)
		return;
	width = n_width;
	height = n_height;

	UnloadTexture(preview);
	Image temp = ImageCopy(picture);
	ImageResize(&temp, width, width);
	preview = LoadTextureFromImage(temp);
	UnloadImage(temp);
}

void	Picture_preview::MOOVE(int n_posx, int n_posy)
{
	pos.x = n_posx;
	pos.y = n_posy;
}