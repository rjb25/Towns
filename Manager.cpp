#include "Manager.h"
#include "Creature.h"
#include "Resource.h"
#include "Entity.h"
#include <iostream>

Manager::Manager(int numCreatures, int numResources){
    for(int i = 0; i < numCreatures; i++){
        SpawnCreature();
    }
    for(int i = 0; i < numResources; i++){
        SpawnResource();
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

std::vector<Entity*> Manager::GetResources(std::vector<Entity*> group){
    std::vector<Entity*> resources;
    for(int i = 0; i < group.size(); i++){
        if(dynamic_cast<Resource*>(group[i]) != nullptr){
            resources.push_back(group[i]);
        }
    }
    return resources;
}
std::vector<Entity*> Manager::Exclude(std::vector<Entity*> group, int priority){
    std::vector<Entity*> entities;
    for(int i = 0; i < group.size(); i++){
        if(priority != group[i]->priority){
            entities.push_back(group[i]);
        }
    }
    return entities;
}
//Stays Entity to make multiple gets and other operations easier. Like get 1st or get most health
std::vector<Entity*> Manager::GetCreatures(std::vector<Entity*> group){
    std::vector<Entity*> creatures;
    for(int i = 0; i < group.size(); i++){
        if(dynamic_cast<Creature*>(group[i]) != nullptr){
            creatures.push_back(group[i]);
        }
    }
    return creatures;
}

void Manager::SpawnCreature(){
        Creature * baby = new Creature(this, 8, std::rand()%5);
        entities.push_back(baby);
}
void Manager::SpawnResource(){
        //Resource * sapling = new Resource(this, 30 + (std::rand() % 20));
        Resource * sapling = new Resource(this, 8);
        entities.push_back(sapling);
}
