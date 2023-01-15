#include "Manager.h"
#include "Creature.h"
#include "Resource.h"
#include "Entity.h"
#include <iostream>

Manager::Manager(int numCreatures, int numResources){
    for(int i = 0; i < numCreatures; i++){
        Creature * baby = new Creature(this, 30 + (std::rand() % 20), std::rand()%5);
        entities.push_back(baby);
    }
    for(int i = 0; i < numResources; i++){
        Resource * sapling = new Resource(this, 30 + (std::rand() % 20));
        entities.push_back(sapling);
    }
}

int Manager::Add(){
    int val = availablePriority;
    availablePriority++;
    return val;
}

void Manager::Remove(int priority){
    availablePriority--;
    entities.erase(entities.begin()+priority);
    for(int i = priority; i < entities.size(); i++){
        entities[i]->priority = entities[i]->priority - 1;
    }
}

void Manager::CleanDead(){
    for(int i = 0; i < entities.size(); i++){
        if(entities[i] == NULL || entities[i]->health <= 0){
            Remove(i);
        }
    }
}

void Manager::Act(bool log){
    for(int i = 0; i < entities.size(); i++){
        if(entities[i]->health > 0){
            entities[i]->Act(log);
        }
    }
}

std::vector<Entity*> Manager::GetResources(std::vector<Entity*> & group){
    std::vector<Entity*> resources;
    for(int i = 0; i < group.size(); i++){
        if(dynamic_cast<Resource*>(group[i]) != nullptr){
            resources.push_back(group[i]);
        }
    }
    return resources;
}
