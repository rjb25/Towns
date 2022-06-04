#include "Manager.h"
#include "Creature.h"
#include "Resource.h"
#include "Entity.h"
#include <iostream>

Manager::Manager(int numCreatures, int numResources){
    std::cout << "Man" << std::endl << std::flush;
    std::vector<Entity*> creatures;
    std::vector<Entity*> resources;
    std::cout << "Man" << std::endl << std::flush;
    for(int i = 0; i < numCreatures; i++){
        Creature * baby = new Creature(this, 30 + (std::rand() % 20), std::rand()%5);
        creatures.push_back(baby);
    }
    std::cout << "Man" << std::endl << std::flush;
    for(int i = 0; i < numResources; i++){
        Resource * sapling = new Resource(this, 30 + (std::rand() % 20));
        resources.push_back(sapling);
    }
    std::cout << "Man" << std::endl << std::flush;
    entities.push_back(resources);
    entities.push_back(creatures);
    std::cout << "Man" << std::endl << std::flush;
}

void Manager::CleanDead(){
    for(int category = 0; category < entities.size(); category++){
        for(int i = 0; i < entities[category].size(); i++){
            if(entities[category][i]->health <= 0){
                entities[category].erase(entities[category].begin()+i);
                i--;
            }
        }
    }
}
