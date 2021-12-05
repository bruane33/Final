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
    //DECLARATIONS
    int input;
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
        if (isPlayed == "true"){
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


    std::ifstream reader2("C:/Users/Brian/Documents/CIS152 Data Structures/Final/unplayed.txt");
    if(!reader2.is_open()){
        std::cout << "Error opening database file." << std::endl;
    }
    while(!reader2.eof()){
        Media temp;
        std::string isPlayed;
        getline(reader2, temp.title);
        getline(reader2, temp.genre);
        getline(reader2, temp.system);
        getline(reader2, isPlayed);
    }
    reader2.close();



    //INTRODUCTION
    std::cout << "Welcome to the Ruane Media Database!\nChoose an option to get started:\n";
    while (input != 0){
    std::cout << "1:Add Media\n2:Remove Media\n3:Next Unplayed Title\n4:Search By Name\n5:Search By Genre\n6:Search by System\n7:Search by ID\n8:List All\n9:List All Unplayed\n0:Quit\n";
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
        system("CLS");// ADD MEDIA
        Media temp;
        std::cout << "ADD MEDIA" << std::endl;
        temp = addMedia();
        database.insert({keyID.back(), temp});
        unplayedQueue.push(keyID.back()); //add new added media to queue of unplayed
        keyID.push_back(keyID.back()+1);
        std::ofstream writer;
        std::ofstream writer2;
        writer.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt",std::ios::app);
        writer << "\n" << temp.title << "\n";
        writer << temp.genre << "\n";
        writer << temp.system << "\n";
        writer << temp.played << "\n";
        writer.close();
        writer2.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/unplayed.txt",std::ios::app);
        writer2 << "\n" << temp.title << "\n";
        writer2 << temp.genre << "\n";
        writer2 << temp.system << "\n";
        writer2.close();
        break;
    }
    case 2:{
        system("CLS");//REMOVE MEDIA
        Media temp;
        int erase = removeMedia(database);
        std::ofstream writer3;
        writer3.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt", std::ofstream::out | std::ofstream::trunc);
        writer3.close();
        writer3.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt",std::ios::app);
        for(auto& find : database){
            if (find.first != erase){
                writer3 << find.second.title << "\n";
                writer3 << find.second.genre << "\n";
                writer3 << find.second.system << "\n";
                writer3 << find.second.played << "\n";
            }
        }
        database.erase(erase);
        break;
    }
    case 3:{
        system("CLS");//NEXT UNPLAYED
        int result = searchUnplayed(database, unplayedQueue);
        int played;
        std::cout << "\n1:Finished Game\n2:Next Title\n3:Back to Main\n" << std::endl;
        std::cin >> played;
        while (!std::cin || played < 1 || played > 3){
            std::cout << "Input must be integer 1 through 3. Please try again.\n";
            std::cin >> played;
            std::cin.ignore();
        }
        switch (played){
        case 1:{
            for(auto& find : database){
                if(find.first == result){
                    find.second.played = true;
                }
            }
            std::ofstream writer4;
            writer4.open("C:/Users/Brian/Documents/CIS152 Data Structures/saveditems.txt", std::ofstream::out | std::ofstream::trunc);
            writer4.close();
            writer4.open("C:/Users/Brian/Documents/CIS152 Data Structures/saveditems.txt",std::ios::app);
            for(auto& find : database){
                    writer4 << find.second.title << "\n";
                    writer4 << find.second.genre << "\n";
                    writer4 << find.second.system << "\n";
                    if(find.second.played == true){
                        writer4 << "true" << "\n";
                    }else{
                        writer4 << "false" << "\n";
                    }
            }
            unplayedQueue.pop();
            std::cout << "Game removed from unplayed queue!\n" << std::endl;
            break;
        }
        case 3:{
            break;
        }
        }

        break;
    }
    case 4: //SEARCH BY NAME
        system("CLS"); //Clear Screen
        searchByName(database);
        break;
    case 5:
        system("CLS");//SEARCH BY GENRE
        searchByGenre(database);
        break;
    case 6:
        system("CLS");//LIST ALL
        searchBySystem(database);
        break;
    case 7:
        system("CLS");
        searchByID(database);
        break;
    case 8:
        system("CLS");
        listAll(database);
        break;
    case 9:
        //listAllUnplayed(database,unplayedQueue);
        for (int i = 0; i < unplayedQueue.size(); ++i){
            std::cout << unplayedQueue.top() << std::endl;
            unplayedQueue.pop();
        }
        break;
    }
    //system("CLS");
    reader.close();
    reader2.close();
    }
    return 0;
}















