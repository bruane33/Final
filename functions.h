#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "media.h"
#include <map>
#include <queue>

Media addMedia();
void listAll(std::map<int,Media>&);
void searchByName(std::map<int,Media>&);
void searchByGenre(std::map<int,Media>&);
void searchBySystem(std::map<int,Media>&);
void searchByID(std::map<int,Media> &x);
int removeMedia(std::map<int,Media> &x);
int searchUnplayed(std::map<int,Media>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&);
void listAllUnplayed(std::map<int,Media>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&);











#endif // FUNCTIONS_H
