#include "Entity.h"
#include "Manager.h"
#include <iostream>

Entity::Entity(Manager * manager, int health){
    this->manager = manager;
    this->health = health;
}

void Entity::Act(bool print){
    if(print){
        std::cout << "My health is " << health << std::endl;
    }
    //Base functions of things that exist 
}
