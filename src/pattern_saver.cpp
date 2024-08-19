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

void	Pattern_saver::RESIZE_Pattern_Saver()
{
	width = GetScreenWidth();
	height = GetScreenHeight();
	saver.RESIZE(width, height);
	searcher.RESIZE(width, height);
}

void	Pattern_saver::HANDLE_Input()
{
	if (IsWindowResized())
		RESIZE_Pattern_Saver();

	int	click(0);

	if (IsMouseButtonPressed(0))
	{
		mouse_pos = GetMousePosition();
		click = 1;
	}

	if (mod == SAVER)
	{
		if (click)
			saver.CLICK(mouse_pos);
		if (mod == SAVER && saver.TEXT_Inp_Open())
			saver.TEXT_Inp();
	}

	else if (mod == SEARCHER)
	{
		if (click)
			searcher.CLICK(mouse_pos);
		searcher.HANDLE_Mouse_Wheel();
		//if (searcher.TEXT_Inp_Open())
		//	searcher.TEXT_Inp();
	}
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
