#include "Entity.h"
#include <iostream>

Entity::Entity(int health){
    this->health = health;
}

void Entity::Act(){
    this->health -= 1;
    std::cout << "My health is " << health << std::endl;
    //In subclass have animal AI for choosing between forage, fight, mate
    //Have plant Ai for... being eaten?
    
}
