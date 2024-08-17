#ifndef TEXT_AREA_HPP
# define TEXT_AREA_HPP

#include "pattern.hpp"

class Text_area
{
    private:
        Vector2     pos;
        std::string name;
        int         name_width;
        std::string text;
        std::string displayed_text;
        int         max_char_per_line;
        int         width;
        int         height;
        int         char_size;
        Color       color;
        int         scroll;

    public:
        //Text_area(){}
        Text_area(Vector2 n_pos, std::string n_name, int n_width, int n_height, Color n_color);
        ~Text_area();

        int     IS_Clicked(Vector2 click_pos);
        void    DISPLAY_Area();
        int     Input_text();
        int     CLICK_Outside_Text_Area();

        void    RESET() { text.clear(); displayed_text.clear(); }

        Vector2     POS() { return (pos); }
        int         WIDTH() { return (width); }
        int         HEIGHT() { return (height); }
        Color       COLOR() { return (color); }
        std::string NAME() {return (name); }
        int         NAME_Width() { return (name_width); }

        void        Print_width() { std::cout << width << std::endl << height << std::endl; }
        std::string GET_Text() { std::cout << text << std::endl; return (text); }
        void        CREATE_Displayed_Text();
        void        SCROLL(int i) { scroll += -i; if (scroll < 0)scroll++; }
};

#endif
