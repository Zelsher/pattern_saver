#ifndef BUTTON_HPP
# define BUTTON_HPP

#include "pattern.hpp"

class Button 
{
    private:
        Vector2 pos;
        std::string  name;
        int         width;
        int         height;
        Color       color;

        int         name_width;

    public:
        //Button();
        Button(Vector2 n_pos, std::string n_name, int n_width, int n_height, Color n_color);
        ~Button();
    
        int     IS_Clicked(Vector2 click_pos);
        void    DISPLAY_Button();


        Vector2     POS() { return (pos); }
        int         WIDTH() { return (width); }
        int         HEIGHT() { return (height); }
        Color       COLOR() { return (color); }
        std::string NAME() {return (name); }
        int         NAME_Width() { return (name_width); }
};

#endif