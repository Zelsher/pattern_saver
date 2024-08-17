#include "../inc/pattern_saver.hpp"

Pattern::Pattern(Vector2 n_pos, std::string n_name, std::string n_path, int n_width, int n_height) : name(n_name), path(n_path), width(n_width), height(n_height), play(Vector2{pos.x + width / 15, pos.y + height / 4}, "Play", height / 2, height / 2, DARKBLUE)
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

void	Pattern::CLICK(Vector2 pos)
{
	if (play.IS_Clicked(pos))
		PLAY_Wav();
}

void	Pattern::DISPLAY()
{
	//std::cout << ">>" << std::endl << pos.x << std::endl << pos.y << std::endl << width << std::endl << height << std::endl << "<<" << std::endl;
	DrawRectangle(pos.x, pos.y, width, height, color);
	DrawRectangle(pos.x, pos.y, width, 1, BLACK);
	play.DISPLAY_Button();
	DrawText(name.c_str(), pos.x + width / 2 - char_size / 2, pos.y + height / 2 - char_size / 2, char_size, BLACK);
}
