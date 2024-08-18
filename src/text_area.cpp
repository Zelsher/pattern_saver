#include "../inc/pattern_saver.hpp"

Text_area::Text_area(Vector2 n_pos, std::string n_name, int n_width, int n_height, int n_font, Color n_color) 
{
	pos = n_pos;
	name = n_name;
	width = n_width;
	height = n_height;
	color = n_color;
	n_line_displayed = 0;
	scroll = 0;
	name_width = MeasureText(name.c_str(), width);
	n_char = 1;
	font = n_font;
	if (font == 0)
		font = 26;
}

Text_area::~Text_area()
{
	std::cout << "destructor text_area called on " << name << std::endl;
}

int    Text_area::IS_Clicked(Vector2 click_pos)
{
	if (click_pos.x > pos.x && click_pos.x < pos.x + width
		&& click_pos.y > pos.y && click_pos.y < pos.y + height)
		return (1);
	return (0);
}

int     Text_area::CLICK_Outside_Text_Area()
{
	if (!IsMouseButtonPressed(0))
		return (0);
	Vector2 mouse_pos = GetMousePosition();
	if (!IS_Clicked(mouse_pos))
		return (1);
	return (0);
}

void    Text_area::CREATE_Displayed_Text(int key)
{
	max_char_per_line = width / char_size - 4;
	max_line_displayed = height / (char_size * 1.5) - 1;
	if (key == KEY_BACKSPACE)//retirer un charactere
	{
		if (!displayed_text.empty() && displayed_text.back() == '\n')
		{
			n_line_displayed--;
			scroll--;
			n_char = max_char_per_line - 1;
		}
		if (!displayed_text.empty())
			displayed_text.pop_back();
		return;
	}
	if (!text.empty())//ajouter un charactere
	{
		displayed_text += text.back();
		n_char++;
		if (key == KEY_ENTER)
		{
			std::cout << key << std::endl;
			if (max_line_displayed <= n_line_displayed)
				scroll++;
			n_line_displayed++;
			n_char = 1;
		}
			
	}
	if (n_char == max_char_per_line)//adapter laffichage
	{
		n_char = 1;
		displayed_text += '\n';
		n_line_displayed++;
		if (max_line_displayed <= n_line_displayed)
			scroll++;
	}
}

int    Text_area::Input_text()
{
	//MeasureText("a", (width * height) * 0.001f) > height
	SCROLL((int)GetMouseWheelMove());
	int key = GetKeyPressed();
	if ((key < 32 || key > 122) && (key != KEY_BACKSPACE && key != KEY_ENTER))
		return(0);
	if (key == KEY_BACKSPACE && !text.empty())
		text.pop_back();
	else if (key == KEY_ENTER)
		text += "\n";
	else if (key != KEY_BACKSPACE)
	{
		if (!(key >= 65 && key <= 90) || IsKeyDown(KEY_LEFT_SHIFT)) 
			text += (char)key;
		else
			text += (char)(key + 32);
	}
	CREATE_Displayed_Text(key);
	return (0);
}

void    Text_area::DISPLAY_Area()
{
	char_size = MeasureText("a", font);
	DrawRectangle(pos.x, pos.y, width, height, WHITE);
	DRAW_Outline(pos, width, height);

	if (text.empty())
			DrawText(name.c_str(), pos.x + width / 2 - MeasureText(name.c_str(), (width * height) * 0.001f) / 2,
				pos.y + height / 2 - MeasureText("a", (width * height) * 0.001f), (width * height) * 0.001f, BLACK);
	else
	{
		std::istringstream flux(displayed_text);
		std::string line;
		int max_line_displayed = height / (char_size * 1.5) - 1;
		for (int i = 0; scroll > i; i++)// passer les lignes scroller
			std::getline(flux, line);
		for (int i = 0; std::getline(flux, line) && max_line_displayed > i; i++) 
		{
			DrawText(line.c_str(), pos.x, pos.y + (char_size * 1.5) * i, font, BLACK);
		}
	}
}


void    Text_area::MOOVE(int n_posx, int n_posy)
{
	pos.x = n_posx;
	pos.y = n_posy;
}

void    Text_area::RESIZE(int n_width, int n_height)
{
	width = n_width;
	height = n_height;
}
