#ifndef PATTERN_HPP
# define PATTERN_HPP

#include "pattern_saver.hpp"

class Button;

class Pattern 
{
    private:
        Vector2 pos;
        std::string name;
        std::string path;
        std::string wav_file;
        std::string description_file;
        int     width;
        int     height;
        int     char_size;
        Button  play;
        Color   color;
    public:
        Pattern(Vector2 pos, std::string n_name, std::string n_path, int n_width, int n_height);
        ~Pattern();
        void    CLICK(Vector2 pos);
        void    DISPLAY();
        void    PLAY_Wav();
};

#endif