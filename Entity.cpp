#include "Entity.h"
#include "Manager.h"
#include <iostream>

Entity::Entity(Manager * manager, int health){
    this->manager = manager;
    this->health = health;
    this->priority = manager->Add();
}

void Entity::Act(bool print){
    if(print){
        std::cout << "My health is " << health << std::endl;
    }
    //Base functions of things that exist 
}
