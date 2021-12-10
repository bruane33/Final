#include "media.h"
#include <iostream>

//Media class
Media::Media()
{
    title = "N/A";
    genre = "N/A";
    system = "N/A";
    played = false;
}

Media::Media(std::string x,std::string y, std::string z){
    title = x;
    genre = y;
    system = z;
}
