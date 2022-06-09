#include <iostream>
#include <string>
#include "Entity.h"
#include "Creature.h"
#include "Resource.h"
#include "Manager.h"
#include <stdlib.h>
#include <vector>

int
main(int argc, char const* argv[]) {
    Manager * manager = new Manager(3,3);
    bool running = true;
    int times = 1;
    while(running){
        std::cout << "Run how many times? (Stop = 0)" << std::endl;
        std::cin >> times;
        if(times == 0){
            running = false;
        }
        for(int time = 0; time < times; time++){
            for(int i = 0; i < manager->entities.size(); i++){
                manager->entities[i]->Act(true);
            }
            manager->CleanDead();
        }
    }
    return 0;
}
