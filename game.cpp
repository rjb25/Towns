#include <iostream>
#include <string>
#include "Entity.h"
#include <vector>

int
main(int argc, char const* argv[]) {
    std::cout << "hey" << std::endl;
    std::vector<Entity*> entities;
    entities.push_back(new Entity(40));
    entities.push_back(new Entity(50));
    entities.push_back(new Entity(60));
    bool running = true;
    std::string stop = "";
    while(running){
        for(int i = 0; i < entities.size(); i++){
            entities[i]->Act();
        }
        std::cout << "Stop? (y)" << std::endl;
        std::cin >> stop;
        if(stop == "y"){
            running == false;
        }
    }
    return 0;
}
