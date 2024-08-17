#include "../inc/pattern_saver.hpp"

int main()
{
    Pattern_saver pattern;
    while (!WindowShouldClose())
    {
        pattern.DISPLAY();
    }
}