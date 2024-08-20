#include "../inc/pattern_saver.hpp"

Pattern::Pattern(Vector2 n_pos, std::string n_name, std::string n_path, int n_width, int n_height) : name(n_name), path(n_path), width(n_width), height(n_height), play(Vector2{pos.x + width / 15, pos.y + height / 4}, "Play", height / 2, height / 2, DARKBLUE), description_button(Vector2{pos.x + width / 2 - (width / 5) / 2, pos.y}, "Desciption", width / 5, height, DARKBLUE), img_preview(path + "/" + name + ".png", Vector2{pos.x + (pos.x + width / 3) * 2, pos.y}, width / 3, height)
{
	pos = n_pos;
	//std::cout << name << std::endl;
	wav_file = path + "/" + name + ".wav";
	color = Color{76, 76, 76, 255};
	char_size = MeasureText("a", 26);
}

Pattern::~Pattern()
{
	
}

void	Pattern::PLAY_Wav()
{
	Sound play_wav = LoadSound(wav_file.c_str());
	PlaySound(play_wav);
	UnloadSound(play_wav);
}

int	Pattern::CLICK(Vector2 n_pos)
{
	if (play.IS_Clicked(n_pos))
		PLAY_Wav();
	else if (img_preview.IS_Clicked(n_pos))
		return (IMG_PREVIEW);
	else if (description_button.IS_Clicked(n_pos))
	{
		std::cout << "oui" << std::endl;
		return (DESCRIPTION_PREVIEW);
	}
	return (0); 
}

void	Pattern::CREATE_Description(int win_width, int win_height)
{
	description = new Text_area(Vector2{0, 0}, "Description", win_width, win_height, 0, WHITE);
}

void	Pattern::DESTROY_Description()
{
	delete description;
	description = NULL;
}

void	Pattern::DISPLAY_Description(int win_width, int win_height)
{
	if (win_width != description->WIDTH() && win_height != description->HEIGHT())
		description->RESIZE(win_width, win_height);
	description->DISPLAY_Area();
}

void	Pattern::DISPLAY()
{
	//std::cout << ">>" << std::endl << pos.x << std::endl << pos.y << std::endl << width << std::endl << height << std::endl << "<<" << std::endl;
	DrawRectangle(pos.x, pos.y, width, height, color);
	DRAW_Outline(pos, width, height);

	play.DISPLAY_Button();
	img_preview.DISPLAY();
	description_button.DISPLAY_Button();
	DrawText(name.c_str(), pos.x + width / 2 - char_size / 2, pos.y + height / 2 - char_size / 2, char_size, WHITE);
}

void    Pattern::MOOVE(int n_posx, int n_posy)
{
	pos.x = n_posx;
	pos.y = n_posy;
	play.MOOVE(pos.x + width / 15, pos.y + height / 4);
	description_button.MOOVE(pos.x + width / 2 - (width / 5) / 2, pos.y);
	img_preview.MOOVE(pos.x + (pos.x + width / 3) * 2, pos.y);
}

void    Pattern::RESIZE(int n_width, int n_height)
{
	width = n_width;
	height = n_height;
	play.RESIZE(height / 2, height / 2);
	description_button.RESIZE(width / 5, height);
	img_preview.MOOVE((pos.x + width / 3) * 2, pos.y);
	img_preview.RESIZE(width / 3, height);
}
