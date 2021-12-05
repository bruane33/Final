#include "functions.h"
#include <iomanip>
#include <vector>
#include <fstream>

void styleLine1(){
    std::cout << "*------------------------------------------------------------------------*\n";
}

void styleLine2(){
    std::cout << "*[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]*\n";
}

void listAll(std::map<int,Media> &x){
    system("CLS");
    std::cout << "Full List of Available Games" << std::endl;
    std::cout << "Key ID:\t\t\t   Title:\t            Genre:     System:\n";
    styleLine1();
    for (auto const &pair: x){
        std::cout << pair.first << "\t" << std::setw(25) << std::right << pair.second.title << std::setw(25) << std::right << pair.second.genre << std::setw(12) << std::right << pair.second.system << std::endl;
        std::cout << std::endl;
    }
    styleLine2();
}

void listAllUnplayed(std::map<int,Media> &database, std::priority_queue<int, std::vector<int>, std::greater<int>> &unplayedQueue){
    system("CLS");
    std::vector<int> tempHold;
    std::cout << "List of Unfinished Games" << std::endl;
    std::cout << "Key ID:\t\t\t   Title:\t            Genre:     System:\n";
    for (unsigned long long i = 0; i < unplayedQueue.size(); ++i){ //problem
        std::cout << unplayedQueue.top() << std::endl;
        tempHold.push_back(unplayedQueue.top());
        for(auto& find : database){
            if(find.first == unplayedQueue.top()){
                std::cout << find.first << "\t" << std::setw(25) << std::right << find.second.title << std::setw(25) << std::right << find.second.genre << std::setw(12) << std::right << find.second.system << std::endl;
            }
        }
        unplayedQueue.pop();
    }
    for (unsigned long long i = 0; i < tempHold.size(); ++i){
        unplayedQueue.push(tempHold.at(i));
    }
    styleLine2();
}

void searchUnplayed(std::map<int,Media> &database, std::priority_queue<int, std::vector<int>, std::greater<int>> &unplayedQueue){
    system("CLS");
    int input;
    int search = unplayedQueue.top();
    for(auto& find : database){
        if(find.first == search){
            std::cout << "\nNEXT UNPLAYED GAME" << std::endl;
            std::cout << "Title: " << find.second.title << "\nGenre: " << find.second.genre << "\nLocation: " << find.second.system << std::endl;
        }
    }
    std::cout << "\n1:Finished Game\n2:Back to Main\n" << std::endl;
    std::cin >> input;
    while (!std::cin || input < 1 || input > 2){
        std::cout << "Input must be integer 1 or 2. Please try again.\n";
        std::cin >> input;
        std::cin.ignore();
    }
    switch (input){
    case 1:{
    for(auto& find : database){
        if(find.first == search){
            find.second.played = true;
        }
    }
    std::ofstream writer4;
    writer4.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt", std::ofstream::out | std::ofstream::trunc);
    writer4.close();
    writer4.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt",std::ios::app);
    for(auto& find : database){
            writer4 <<"\n" << find.second.title << "\n";
            writer4 << find.second.genre << "\n";
            writer4 << find.second.system << "\n";
            if(find.second.played == true){
                writer4 << "true";
            }else{
                writer4 << "false";
            }
    }
    unplayedQueue.pop();
    std::cout << "Game removed from unplayed queue!\n" << std::endl;
    break;
    }
    case 2:{
        break;
    }
    }
}

void addMedia(std::map<int,Media>&database, std::priority_queue<int, std::vector<int>, std::greater<int>>&unplayedQueue, std::vector<int>&keyID){
    system("CLS");
    Media temp;
    std::cout << "ADD MEDIA" << std::endl;
    styleLine1();
    std::cout << "What is the title of the game?" << std::endl;
    std::getline(std::cin, temp.title);
    std::cout << "What is the genre of the game?" << std::endl;
    std::getline(std::cin,temp.genre);
    std::cout << "What system is the game on?" << std::endl;
    std::getline(std::cin,temp.system);
    temp.played = false;
    std::cout << "\nNew entry:\nTitle: " + temp.title + "\nGenre: " + temp.genre + "\nSystem: " + temp.system + "\n\n";    
    database.insert({keyID.back(), temp});
    unplayedQueue.push(keyID.back()+1);
    keyID.push_back(keyID.back()+1);
    std::ofstream writer;
    std::ofstream writer2;
    writer.open("C:/Users/Brian/Documents/CIS152 Data Structures/Final/saveditems.txt",std::ios::app);
    writer << "\n" << temp.title << "\n";
    writer << temp.genre << "\n";
    writer << temp.system << "\n";
    writer << "false";
    writer.close();
}

void searchByName(std::map<int,Media> &x){
    system("CLS");
    std::string search;
    std::cout << "Enter title to be searched:" << std::endl;
    std::getline(std::cin,search);
    bool notFound = true;
    for(auto& find : x){
        if(find.second.title == search){
            std::cout << "\nITEM FOUND" << std::endl;
            std::cout << "Title: " << find.second.title << "\nGenre: " << find.second.genre << "\nLocation: " << find.second.system << std::endl;
            notFound = false;
        }
    }
    if (notFound){
        std::cout << "No Item Found\n" << std::endl;
    }
}

void searchByGenre(std::map<int,Media> &x){
    system("CLS");
    std::string search;
    std::cout << "Enter genre to be searched:" << std::endl;
    std::cin >> search;
    bool notFound = true;
    for(auto& find : x){
        if(find.second.genre == search){
            std::cout << "\nITEM FOUND" << std::endl;
            std::cout << "Title: " << find.second.title << "\nGenre: " << find.second.genre << "\nLocation: " << find.second.system << std::endl;
            notFound = false;
        }
    }
    if (notFound){
        std::cout << "No Item Found\n" << std::endl;
    }
}

void searchBySystem(std::map<int,Media> &x){
    system("CLS");
    std::string search;
    std::cout << "Enter system to be searched:" << std::endl;
    std::cin >> search;
    bool notFound = true;
    for(auto& find : x){
        if(find.second.system == search){
            std::cout << "\nITEM FOUND" << std::endl;
            std::cout << "Title: " << find.second.title << "\nGenre: " << find.second.genre << "\nLocation: " << find.second.system << std::endl;
            notFound = false;
        }
    }
    if (notFound){
        std::cout << "No Item Found\n" << std::endl;
    }
}

void searchByID(std::map<int,Media> &x){
    system("CLS");
    int search;
    std::cout << "Enter ID to be searched:" << std::endl;
    std::cin >> search;
    bool notFound = true;
    for(auto& find : x){
        if(find.first == search){
            std::cout << "\nITEM FOUND" << std::endl;
            std::cout << "Title: " << find.second.title << "\nGenre: " << find.second.genre << "\nLocation: " << find.second.system << std::endl;
            notFound = false;
        }
    }
    if (notFound){
        std::cout << "No Item Found" << std::endl;
    }
}

void removeMedia(std::map<int,Media> &database, std::priority_queue<int, std::vector<int>, std::greater<int>>& unplayedQueue){
    system("CLS");
    int erase;
    std::string remove;
    std::cout << "What is the title to be removed?\n";
    std::getline(std::cin, remove);
    bool notFound = true;
    for(auto& find : database){
        if(find.second.title == remove){
            notFound = false;
            erase = find.first;
        }
    }
    if (notFound){
        std::cout << "No Item Found" << std::endl;
        erase = 0;
    }
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
}


