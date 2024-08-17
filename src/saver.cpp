#include "../inc/pattern.hpp"

Saver::Saver(Pattern *p_pattern) : searcher(Vector2{BASE_WIDTH / 2, BASE_HEIGHT - BASE_HEIGHT / 5}, "searcher", BASE_WIDTH / 2, BASE_HEIGHT / 5, Color{76, 76, 76, 255}),
                                    save(Vector2{0, BASE_HEIGHT - BASE_HEIGHT / 5}, "save", BASE_WIDTH / 2, BASE_HEIGHT / 5, Color{0, 141, 31, 255}),
                                    pattern(p_pattern),
                                    area_click(0)
{
    text_area.emplace_back(Vector2{BASE_WIDTH / 2 + BASE_WIDTH / 20, BASE_HEIGHT / 10}, "Name", BASE_WIDTH / 2 - BASE_WIDTH / 18, BASE_HEIGHT / 5, WHITE);
    text_area.emplace_back(Vector2{0 + BASE_WIDTH / 20, BASE_HEIGHT / 20}, "Description", BASE_WIDTH / 2 - BASE_WIDTH / 18, BASE_HEIGHT / 2, WHITE);     
}

Saver::~Saver()
{
    std::cout << "destructor called" << std::endl;
}

void   Saver::save_pattern()
{
    //std::filesystem
    if (text_area.empty()) 
        return;
    std::cout << text_area[0].GET_Text() << std::endl;
    std::string pattern_name = text_area[0].GET_Text();
    std::string wave_file = pattern_name + ".wav";
    text_area[0].RESET();
    if (!std::filesystem::exists(SAVE_FOLDER))
        std::filesystem::create_directory(SAVE_FOLDER);

    std::cout << WAV_FOLDER + wave_file << std::endl;
    std::ifstream source(WAV_FOLDER + wave_file, std::ios::binary);
    if (!source)
    {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier source." << std::endl;
        return;
    }

    std::ofstream dest(SAVE_FOLDER + wave_file, std::ios::binary);
    if (!dest) 
    {
        std::cerr << "Erreur: Impossible de créer le fichier de destination." << std::endl;
        return;
    }
    dest << source.rdbuf();
    source.close();
    dest.close();

    std::ofstream name(SAVE_FOLDER + pattern_name);
    if (!name) 
    {
        std::cerr << "Erreur: Impossible de créer le fichier name" << std::endl;
        return ;
    }
    name << text_area[1].GET_Text();
    text_area[1].RESET();
    //takeScreenshot(pattern_name);
}

void   Saver::CLICK(Vector2 mouse_pos)
{
    area_click = 0;
    if (save.IS_Clicked(mouse_pos))
    {
        save_pattern();
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
    text_area[area_click - 1].Input_text();
}