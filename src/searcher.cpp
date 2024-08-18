#include "../inc/pattern_saver.hpp"

Searcher::Searcher(Pattern_saver *p_pattern) : saver(Vector2{0, BASE_HEIGHT - BASE_HEIGHT / 5}, "Saver", BASE_WIDTH, BASE_HEIGHT / 5, BLUE), pattern_saver(p_pattern), id_open_text(0), scroll(0)
{
	width = BASE_WIDTH;
	height = BASE_HEIGHT;
}

void    Searcher::RESIZE(int n_width, int n_height)
{
	saver.RESIZE(n_width, n_height / 5);
	saver.MOOVE(0, n_height - n_height / 5);

	width = n_width;
	height = n_height;
}

Searcher::~Searcher()
{
	std::cout << "destructor called" << std::endl;
}

void   Searcher::CLICK(Vector2 mouse_pos)
{
	if (saver.IS_Clicked(mouse_pos))
	{
		std::cout << "saver clicked" << std::endl;
		pattern_saver->CHANGE_Mod(SAVER); 
	}
	for (size_t i = 0; i < pattern.size(); i++)
	{
		pattern[i].CLICK(mouse_pos);
	}
}

void    Searcher::DISPLAY()
{
	int height_used = 0;
	pattern_height = height / 5;

	saver.DISPLAY_Button();
	for (size_t i = 0; height - height / 5 > height_used && pattern.size() > i; i++)
	{
		pattern[i].DISPLAY();
		height_used += pattern_height;
	}
}

namespace fs = std::filesystem;

void Searcher::UPDATE() 
{
	scroll -= GetMouseWheelMove();
	if (scroll < 0)
		scroll = 0;
	if (!pattern.empty())
		pattern.clear();
	if (!fs::exists(SAVE_FOLDER)) 
	{
		std::cerr << "Save_folder dont exist" << std::endl;
		return;
	}

	int folderCount = 0;
	std::string folder_name;
	std::string file_name;

	int i = 0;
	int j = 0;
	for (const auto& entry : fs::directory_iterator(SAVE_FOLDER)) 
	{
		if (entry.is_directory())
		{
			folderCount++;
			folder_name = entry.path().filename().string();

			for (const auto& file : fs::directory_iterator(entry.path())) 
			{
				if (file.is_regular_file())
					file_name = file.path().filename().string();// verifier les extensions
			}
		}
		if (scroll <= i)
		{
			if (!folder_name.empty())
				pattern.emplace_back(Vector2{0, (float)j * (height / 5)}, folder_name, SAVE_FOLDER + folder_name, width, height / 5);
			folder_name.clear();
			j++;
		}
		i++;
	}
	n_folder = folderCount;
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