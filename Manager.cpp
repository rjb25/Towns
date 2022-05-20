#include "Manager.h"
#include <iostream>

Manager::Manager(int numCreatures, int numResources){
    for(int i = 0; i < numCreatures; i++){
        Creature baby = new Creature(this, 30 + (std::rand() % 20), std::rand()%5);
        creatures.push_back(baby);
    }
    for(int i = 0; i < numResources; i++){
        Resource sapling = new Resource(this, 30 + (std::rand() % 20));
        resources.push_back(sapling);
    }
    entities[0] = resources;
    entities[1] = creatures;
}

void Manager::CleanDead(){
    for(int category = 0; category < entities.size(); category++){
        for(int i = 0; i < entities[category].size(); i++){
            if(entities[category][i]->health <= 0){
                entities[category].erase(entities.begin()+i);
                i--;
            }
        }
    }
}
