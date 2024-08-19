#include "../inc/pattern_saver.hpp"

void testButton() {
    Vector2 pos = {100, 100};
    Button button(pos, "Test", 200, 50, BLUE);
    // Destruction de l'objet en quittant la portée
}


int main()
{

	testButton();
	Pattern_saver pattern;
	while (!WindowShouldClose())
	{
		pattern.DISPLAY();
	}
}