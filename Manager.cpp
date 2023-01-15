#include "Manager.h"
#include "Creature.h"
#include "Resource.h"
#include "Entity.h"
#include <iostream>

Manager::Manager(int numCreatures, int numResources){
    for(int i = 0; i < numCreatures; i++){
        Creature * baby = new Creature(this, 30 + (std::rand() % 20), std::rand()%5);
        creatures.push_back(baby);
        entities.push_back(baby);
    }
    for(int i = 0; i < numResources; i++){
        Resource * sapling = new Resource(this, 30 + (std::rand() % 20));
        resources.push_back(sapling);
        entities.push_back(sapling);
    }
}

void Manager::CleanDead(std::vector<Entity*> & group){
    for(int i = 0; i < group.size(); i++){
        if(group[i] == NULL || group[i]->health <= 0){
            group.erase(group.begin()+i);
            i--;
        }
    }
}
