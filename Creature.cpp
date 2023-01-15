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
    health -= 1;
    int action = std::rand()%3;
    switch(action){
        //Forage
        case 0:
            {
                manager->CleanDead(manager->resources);
                if(manager->resources.size() > 0){
                    int target = std::rand()%manager->resources.size();
                    manager->resources[target]->health-=attack;
                    health += attack;
                }

            break;
            }
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
