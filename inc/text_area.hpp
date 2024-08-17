#ifndef TEXT_AREA_HPP
# define TEXT_AREA_HPP

#include "pattern_saver.hpp"

class Text_area
{
    private:
        Vector2     pos;
        std::string name;
        int         name_width;
        int         char_size;
        int         font;

        /*Text relativ*/
        std::string text;
        std::string displayed_text;
        int         n_char;
        int         max_char_per_line;
        int         n_line_displayed;
        int         max_line_displayed;
        int         scroll;
    
        int         width;
        int         height;
        Color       color;

    public:
        //Text_area(){}
        Text_area(Vector2 n_pos, std::string n_name, int n_width, int n_height, int n_font, Color n_color);
        ~Text_area();

        int     IS_Clicked(Vector2 click_pos);
        void    DISPLAY_Area();
        int     Input_text();
        int     CLICK_Outside_Text_Area();

        void    RESET() { text.clear(); displayed_text.clear(); scroll = 0; n_line_displayed = 0; n_char = 1; }

        Vector2     POS() { return (pos); }
        int         WIDTH() { return (width); }
        int         HEIGHT() { return (height); }
        Color       COLOR() { return (color); }
        std::string NAME() {return (name); }
        int         NAME_Width() { return (name_width); }

        void        Print_width() { std::cout << width << std::endl << height << std::endl; }
        std::string GET_Text() { std::cout << text << std::endl; return (text); }
        void        CREATE_Displayed_Text(int key);
        void        SCROLL(int i) { scroll += -i; if (scroll < 0)scroll++;}
};

#endif
