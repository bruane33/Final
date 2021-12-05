#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "media.h"
#include <map>
#include <queue>

void addMedia(std::map<int,Media>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&, std::vector<int>&);
void listAll(std::map<int,Media>&);
void searchByName(std::map<int,Media>&);
void searchByGenre(std::map<int,Media>&);
void searchBySystem(std::map<int,Media>&);
void searchByID(std::map<int,Media>&);
void removeMedia(std::map<int,Media>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&);
void searchUnplayed(std::map<int,Media>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&);
void listAllUnplayed(std::map<int,Media>&, std::priority_queue<int, std::vector<int>, std::greater<int>>&);
void styleLine1();

#endif // FUNCTIONS_H
