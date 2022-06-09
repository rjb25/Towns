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

void Manager::GetResources(){
}
void Manager::GetCreatures(){
}
void Manager::GetEntities(){
}
void Manager::CleanDead(){
    for(int i = 0; i < entities.size(); i++){
        if(entities[i]->health <= 0){
            entities.erase(entities.begin()+i);
            i--;
        }
    }
}
