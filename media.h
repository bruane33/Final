#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>

//Creation of Media class
class Media
{
public:
    std::string title;
    std::string genre;
    std::string system;
    bool played;
    Media();
    Media(std::string, std::string, std::string);
};

#endif // MEDIA_H
