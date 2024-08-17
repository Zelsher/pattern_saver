#include "../inc/pattern_saver.hpp"

Pattern_saver::Pattern_saver() : mod(1), saver(this), searcher(this), width(BASE_WIDTH), height(BASE_HEIGHT)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(width, height, "pattern");
	InitAudioDevice();
	ClearBackground(BLACK);
}

Pattern_saver::~Pattern_saver()
{
	std::cout << "destructor called" << std::endl;
	CloseWindow();
}

void	Pattern_saver::HANDLE_Input()
{
	if (IsMouseButtonPressed(0))
	{
		mouse_pos = GetMousePosition();
		if (mod == SAVER)
			saver.CLICK(mouse_pos);
		else
			searcher.CLICK(mouse_pos);
	}
	if (mod == SAVER && saver.TEXT_Inp_Open())
		saver.TEXT_Inp();
	//else if (mod == SEARCHER && searcher.TEXT_Inp_Open())
		//searcher.TEXT_Inp();
}

void	Pattern_saver::DISPLAY()
{
	HANDLE_Input();

	BeginDrawing();
	ClearBackground(Color{31, 31, 31, 255});
	if(mod == SAVER)
		saver.DISPLAY();
	else if (mod == SEARCHER)
		searcher.DISPLAY();
	EndDrawing();
}
