/**************************************************************
* Name        : Final Project - The Ruane Database
* Author      : Brian Ruane
* Created     : 12/8/2021
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : This program is creates a list of owned videos games using a map. When new items are
*               added they are put on a priority queue until they are marked as played. Items can
*               be search using various search methods. The program menus are navigated using the
*               numpad.
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include <map>
#include <queue>
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include "addMedia.cpp"
#include "functions.h"
#include "media.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <errno.h>
#include <string.h>

int main()
{
    //PRELIMINARY DECLARATIONS
    int input = 1;
    std::map<int,Media> database;
    std::vector <int> keyID;
    keyID.push_back(0);
    std::priority_queue<int, std::vector<int>, std::greater<int>> unplayedQueue;

    //READ TEXT FILE OF INFORMATION
    std::ifstream reader("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt");
    if(!reader.is_open()){
        std::cout << "Error opening database file." << std::endl;
    }
    while(!reader.eof()){
        Media temp;
        std::string isPlayed;
        getline(reader, temp.title);
        getline(reader, temp.genre);
        getline(reader, temp.system);
        getline(reader, isPlayed);
        if (isPlayed == "0"){
            temp.played = true;
        }else{
            temp.played = false;
        }
        database.insert({keyID.back(), temp});
        if (temp.played == false){
            unplayedQueue.push(keyID.back());
        }
        keyID.push_back(keyID.back()+1);
    }
    reader.close();

    //MAIN MENU DISPLAY AND INPUT
    while (input != 0){
    std::cout << "The Ruane Media Database!\nChoose an option to continue:\n";
    styleLine1();
    std::cout << "1:Add Media\n2:Remove Media\n3:Next Unplayed Title\n4:Search By Name\n5:Search By Genre\n6:Search by System\n7:Search by ID\n8:List All\n9:List All Unplayed(Under Construction)\n0:Quit\n";
   // for (int i = 0;i < unplayedQueue.size();++i){
     //   std::cout << unplayedQueue.top();
    //}
    std::cin >> input;
    std::cin.ignore();
    while (!std::cin || input < 0 || input > 9){
        std::cout << "Input must be integer 0 through 9. Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
        std::cin.ignore();
    }

    //MAIN MENU OPTIONS
    switch(input){
    case 1:{
        addMedia(database,unplayedQueue,keyID);
        break;
    }
    case 2:{
        removeMedia(database,unplayedQueue);
        break;
    }
    case 3:{
        searchUnplayed(database,unplayedQueue);
        break;
    }
    case 4:{
        searchByName(database);
        break;
    }
    case 5:{
        searchByGenre(database);
        break;
    }
    case 6:{
        searchBySystem(database);
        break;
    }
    case 7:{
        searchByID(database);
        break;
    }
    case 8:{
        listAll(database);
        break;
    }
    case 9:
        //listAllUnplayed(database,unplayedQueue,keyID);
        std::cout << "\nThis function is not available at this time.\n" << std::endl;
        break;
    }
    reader.close();
    }
    return 0;
}















