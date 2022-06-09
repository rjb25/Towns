#include "Creature.h"
#include "Manager.h"
#include <iostream>
#include <stdlib.h>

Creature::Creature(Manager * manager, int health,int attack)
: Entity(manager, health)
{
    this->attack = attack;
    //Maybe set Damage here?
}

void Creature::Act(bool print){
    Entity::Act(print);
    this->health -= 1;
    int choice = std::rand()%3;
    switch(choice){
        //Forage
        case 0:
            break;
        //Attack
        case 1:
            break;
        //Mate
        case 2:
            break;
        default:
            std::cout << "Undefined choice" << std::endl;
            break;
    }
}
