#include "../inc/pattern_saver.hpp"

Saver::Saver(Pattern_saver *p_pattern) : searcher(Vector2{BASE_WIDTH / 2, BASE_HEIGHT - BASE_HEIGHT / 5}, "searcher", BASE_WIDTH / 2, BASE_HEIGHT / 5, Color{76, 76, 76, 255}),
									save(Vector2{0, BASE_HEIGHT - BASE_HEIGHT / 5}, "save", BASE_WIDTH / 2, BASE_HEIGHT / 5, Color{0, 141, 31, 255}),
									pattern(p_pattern),
									area_click(0)
{
	text_area.emplace_back(Vector2{BASE_WIDTH / 2 + BASE_WIDTH / 40, BASE_HEIGHT / 15}, "Name", BASE_WIDTH / 2 - BASE_WIDTH / 18, BASE_HEIGHT / 5, 0, WHITE);
	text_area.emplace_back(Vector2{0 + BASE_WIDTH / 40, BASE_HEIGHT / 15}, "Description", BASE_WIDTH / 2 - BASE_WIDTH / 18, BASE_HEIGHT / 2, 0, WHITE);     
}

Saver::~Saver()
{
	std::cout << "destructor called" << std::endl;
}

void    Saver::RESIZE(int n_width, int n_height)
{
	searcher.RESIZE(n_width / 2, n_height / 5);
	searcher.MOOVE(n_width / 2, n_height - n_height / 5);

	save.RESIZE(n_width / 2, n_height / 5);
	save.MOOVE(0, n_height - n_height / 5);

	text_area[0].RESIZE(n_width / 2 - n_width / 18, n_height / 5);
	text_area[0].MOOVE(n_width / 2 + n_width / 40, n_height / 15);

	text_area[1].RESIZE(n_width / 2 - n_width / 18, n_height / 2);
	text_area[1].MOOVE(0 + n_width / 40, n_height / 15);
}

void   Saver::SAVE_Pattern()
{
	//erreur
	if (text_area[0].GET_Text().empty()) 
		return;
	
	std::string pattern_name = text_area[0].GET_Text();
	std::string wave_file = pattern_name + ".wav";
	std::string folder = SAVE_FOLDER + pattern_name + '/';
	std::string description = text_area[1].GET_Text();
	text_area[0].RESET();
	text_area[1].RESET();

	if (!std::filesystem::exists(SAVE_FOLDER))
		std::filesystem::create_directory(SAVE_FOLDER);

	if (std::filesystem::exists(folder))
		return;
	std::filesystem::create_directory(folder);
	
	std::ifstream source(WAV_FOLDER + wave_file, std::ios::binary);
	if (!source)
	{
		std::cerr << "Erreur: Impossible d'ouvrir le fichier source." << std::endl;
		return;
	}

	std::ofstream dest(folder + wave_file, std::ios::binary);
	if (!dest) 
	{
		std::cerr << "Erreur: Impossible de créer le fichier de destination." << std::endl;
		return;
	}

	dest << source.rdbuf();
	source.close();
	dest.close();

	std::ofstream description_file(folder + pattern_name + ".description");
	if (!description_file) 
	{
		std::cerr << "Erreur: Impossible de créer le fichier name" << std::endl;
		return ;
	}
	description_file << description;
	//takeScreenshot(pattern_name);
}

void   Saver::CLICK(Vector2 mouse_pos)
{
	area_click = 0;
	if (save.IS_Clicked(mouse_pos))
	{
		SAVE_Pattern();
		std::cout << "save clicked" << std::endl;
	}
	else if (searcher.IS_Clicked(mouse_pos))
	{
		std::cout << "searcher clicked" << std::endl;
		pattern->CHANGE_Mod(SEARCHER);
	}
	for (int i = 0; i < 2; i++)
	{
		if (text_area[i].IS_Clicked(mouse_pos))
			area_click = i + 1;
	}
}

void    Saver::DISPLAY()
{
	save.DISPLAY_Button();
	searcher.DISPLAY_Button();
	for (int i = 0; i < 2; i++)
	{
		text_area[i].DISPLAY_Area();
	}
}

int     Saver::TEXT_Inp_Open()
{
	return (area_click);
}

void    Saver::TEXT_Inp()
{
	text_area[area_click - 1].INPUT_Text();
}