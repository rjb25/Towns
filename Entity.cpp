#include "Entity.h"
#include <iostream>

Entity::Entity(int health){
    this->health = health;
}

void Entity::Act(){
    std::cout << "My health is " << health << std::endl;
}
