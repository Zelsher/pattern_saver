#include "../inc/pattern.hpp"

Pattern::Pattern() : mod(1), saver(this), searcher(this), width(500), height(250)
{
	InitWindow(width, height, "pattern");
	ClearBackground(BLACK);
}

Pattern::~Pattern()
{
	std::cout << "destructor called" << std::endl;
	CloseWindow();
}

void	Pattern::HANDLE_Input()
{
	if (IsMouseButtonPressed(0))
	{
		
		mouse_pos = GetMousePosition();
		if (mod == SAVER)
			saver.CLICK(mouse_pos);
		else
			searcher.CLICK(mouse_pos);
	}
}
void	Pattern::DISPLAY_Saver()
{}

void	Pattern::DISPLAY_Searcher()
{}


void	Pattern::DISPLAY()
{
	HANDLE_Input();

	BeginDrawing();
	ClearBackground(DARKGRAY);
	if(mod == SAVER)
		saver.DISPLAY();
	else if (mod == SEARCHER)
		searcher.DISPLAY();
	EndDrawing();
}
