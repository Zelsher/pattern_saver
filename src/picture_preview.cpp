#include "../inc/pattern_saver.hpp"

Picture_preview::Picture_preview(std::string n_path, Vector2 n_pos, int n_width, int n_height) : valid (1), pos(n_pos), width(n_width), height(n_height)
{
	std::cout << n_pos.x << "x" << n_pos.y << std::endl;
	picture = LoadImage(n_path.c_str());
	if (picture.width <= 0 || picture.height <= 0)
	{
		valid = 0;
		return;
	}

	Image temp = ImageCopy(picture);
	if (temp.width <= 0 || temp.height <= 0)
	{
		valid = 0;
		UnloadImage(picture);
		return;
	}

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
	std::cout << "Picture destructor called on " << std::endl;
	//UnloadImage(picture);
	//UnloadTexture(preview);
}


void	Picture_preview::DISPLAY()
{
	if (valid)
	{

		//std::cout << pos.x << "x" << pos.y << std::endl;
		DrawTexture(preview, pos.x, pos.y, WHITE);
	}
}

void	Picture_preview::DISPLAY_Full_Image(int win_width, int win_height)
{
	if (width != win_width || height != win_height)
		RESIZE(win_width, win_height);
	DrawTexture(preview, 0, 0, WHITE);
}

void	Picture_preview::RESIZE(int n_width, int n_height)
{
	if (!valid)
		return;
	width = n_width;
	height = n_height;

	UnloadTexture(preview);
	Image temp = ImageCopy(picture);
	ImageResize(&temp, width, height);
	preview = LoadTextureFromImage(temp);
	UnloadImage(temp);
}

void	Picture_preview::MOOVE(int n_posx, int n_posy)
{
	pos.x = n_posx;
	pos.y = n_posy;
	//std::cout << pos.x << "x" << pos.y << std::endl;
}

int     Picture_preview::IS_Clicked(Vector2 click_pos)
{
	if (!valid)
		return (0);
	if (click_pos.x > pos.x && click_pos.x < pos.x + width
		&& click_pos.y > pos.y && click_pos.y < pos.y + height)
		return (1);
	return (0);
}