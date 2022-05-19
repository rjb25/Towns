#include "Resource.h"
#include <iostream>

Resource::Resource(int health){
    this->health = health;
}

void Resource::Act(){
    this->health -= 1;
    std::cout << "My health is " << health << std::endl;
    //In subclass have animal AI for choosing between forage, fight, mate
    //Have plant Ai for... being eaten? Maybe seed/mate decisions
    
}
