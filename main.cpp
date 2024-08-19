#include "raylib.h"

int	main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(500, 500, "pattern");
	Texture preview;
	Image picture;
	Image temp;

	while(1)
	{
		BeginDrawing();
		ClearBackground(Color{31, 31, 31, 255});
		EndDrawing();
		picture = LoadImage("saved_pattern/test/test.png");
		if (picture.width <= 0 || picture.height <= 0)
		{
			return 1;
		}
		temp = ImageCopy(picture);

		ImageResize(&temp, 100, 100);
		preview = LoadTextureFromImage(temp);
		DrawTexture(preview, 0, 0, WHITE);
		UnloadImage(temp);
		if (preview.id == 0)
		{
			UnloadImage(picture);
		}
	}
}