#include "functions.h"
#include <iomanip>
#include <vector>

void listAll(std::map<int,Media> &x){
    std::cout << "Key ID:\t\t\t   Title:\t            Genre:     System:\n";
    for (auto const &pair: x){
        std::cout << pair.first << "\t" << std::setw(25) << std::right << pair.second.title << std::setw(25) << std::right << pair.second.genre << std::setw(12) << std::right << pair.second.system << std::endl;
    }
}

/*void listAllUnplayed(std::map<int,Media> &x, std::priority_queue<int>&y){
    std::cout << "Current Unplayed Games" << std::endl;
    std::cout << "Key ID:\t\t\t   Title:\t            Genre:     System:\n";
    std::vector<int> tempList;
    for (int i = 0; i < y.size(); ++i){
        tempList.at(i) = y.top();
        for (auto& find : x){
            if
        }
    }
}*/

int searchUnplayed(std::map<int,Media> &x, std::priority_queue<int, std::vector<int>, std::greater<int>> &y){
    int search = y.top();
    bool notFound = true;
    for(auto& find : x){
        if(find.first == search){
            std::cout << "\nNEXT UNPLAYED GAME" << std::endl;
            std::cout << "Title: " << find.second.title << "\nGenre: " << find.second.genre << "\nLocation: " << find.second.system << std::endl;
            return find.first;
        }
    }
    if (notFound){
        std::cout << "No Item Found" << std::endl;
        return 0;
    }
}

Media addMedia(){
    Media temp;
    std::cout << "What is the title of the game?" << std::endl;
    std::getline(std::cin, temp.title);
    std::cout << "What is the genre of the game?" << std::endl;
    std::getline(std::cin,temp.genre);
    std::cout << "What system is the game on?" << std::endl;
    std::getline(std::cin,temp.system);
    std::cout << "\nNew entry:\nTitle: " + temp.title + "\nGenre: " + temp.genre + "\nSystem: " + temp.system + "\n\n";
    return temp;
}

void searchByName(std::map<int,Media> &x){
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

void searchByID(std::map<int,Media> &x){ //PROBLEM MAY CUT
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

int removeMedia(std::map<int,Media> &x){
    int gameOut;
    std::string remove;
    std::cout << "What is the title to be removed?\n";
    std::getline(std::cin, remove);
    bool notFound = true;
    for(auto& find : x){
        if(find.second.title == remove){
            notFound = false;
            gameOut = find.first;
        }
    }
    if (notFound){
        std::cout << "No Item Found" << std::endl;
        gameOut = 0;
    }
    return gameOut;
}
