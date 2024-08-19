#include "../inc/pattern_saver.hpp"

Searcher::Searcher(Pattern_saver *p_pattern) : saver(Vector2{0, BASE_HEIGHT - BASE_HEIGHT / 5}, "Saver", BASE_WIDTH * 0.9, BASE_HEIGHT / 5, BLUE), pattern_saver(p_pattern), id_open_text(0), scroll(0)
{
	width = BASE_WIDTH;
	height = BASE_HEIGHT;
	mod = 0;
}

void    Searcher::RESIZE(int n_width, int n_height)
{

	width = n_width;
	height = n_height;
	saver.RESIZE(n_width * 0.9, n_height / 5);
	saver.MOOVE(0, n_height - n_height / 5);

	for (size_t i = 0; pattern.size() > i; i++)
		pattern[i].RESIZE(width, height / 5);
}

Searcher::~Searcher()
{
	std::cout << "destructor called" << std::endl;
}

void   Searcher::CLICK(Vector2 mouse_pos)
{
	if (saver.IS_Clicked(mouse_pos) && mod != IMG_PREVIEW)
	{
		std::cout << "saver clicked" << std::endl;
		pattern_saver->CHANGE_Mod(SAVER); 
	}
	if (mod != IMG_PREVIEW)
	{
		int n_mod;
		for (size_t i = 0; i < pattern.size(); i++)
		{
			n_mod = pattern[i].CLICK(mouse_pos);
			if (n_mod)
				mod = n_mod;
			if (n_mod == IMG_PREVIEW)
				n_pattern_img_dispayed = i;
		}
	}
}

void	Searcher::HANDLE_Mouse_Wheel()
{
	if (IsKeyPressed(KEY_BACKSPACE))
	{
		mod = 0;
		pattern[n_pattern_img_dispayed].RESIZE(width, height / 5);
	}
	if (mod != IMG_PREVIEW)
	{
		scroll -= GetMouseWheelMove();
		if (scroll < 0)
			scroll = 0;
		else if (scroll >= n_folder)
			scroll--;
		
		size_t i = 0;
		while ((size_t)scroll > i)
			i++;

		while (pattern.size() > i)
		{
			pattern[i].MOOVE(0, ((float)i - scroll) * (height / 5));
			i++;
		}
	}
}

void    Searcher::DISPLAY()
{
	if (mod != IMG_PREVIEW)
	{
		size_t i = 0;
		int height_used = 0;
		pattern_height = height / 5;

		saver.DISPLAY_Button();
		while ((size_t)scroll > i)
			i++;
		for (; height - height / 5 > height_used && pattern.size() > i; i++)
		{
			pattern[i].DISPLAY();
			height_used += pattern_height;
		}
	}
	else
		pattern[n_pattern_img_dispayed].DISPLAY_Full_Image(width, height);
}

namespace fs = std::filesystem;

void Searcher::UPDATE() 
{
	std::cout<< "called " << std::endl << std::endl;
	if (!pattern.empty())
		pattern.clear();
	if (!fs::exists(SAVE_FOLDER)) 
	{
		std::cerr << "Save_folder dont exist" << std::endl;
		return;
	}
	n_folder = 0;
	std::string folder_name;
	std::string file_name;
	for (const auto& entry : fs::directory_iterator(SAVE_FOLDER)) 
	{
		if (entry.is_directory())
		{
			n_folder++;
			folder_name = entry.path().filename().string();
			if (!folder_name.empty())
				pattern.emplace_back(Vector2{1, 1}, folder_name, SAVE_FOLDER + folder_name, width, height / 5);
			folder_name.clear();
		}
	}
	HANDLE_Mouse_Wheel();
}

int     Searcher::TEXT_Inp_Open()
{
	return (id_open_text);
}

void    Searcher::TEXT_Inp()
{

}
/*
bool END_With(const std::string str, const std::string suffix) {
	// Vérifier que la taille du suffixe ne dépasse pas celle de la chaîne
	if (str.size() >= suffix.size()) {
		// Extraire les derniers caractères et comparer
		return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
	} else {
		return false;  // La chaîne est trop courte pour contenir le suffixe
	}
}*/