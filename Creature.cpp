#include "Creature.h"
#include "Resource.h"
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
    int action = 0;//std::rand()%3;
    switch(action){
        //Forage
        case 0:
            {
                std::vector<Entity*> resources = manager->GetResources(manager->entities);
                if(resources.size() > 0){
                    int target = std::rand()%resources.size();
                    Entity* resource = resources[target];
                    if(resource->health > 0){
                        resource->health-=attack;
                        if(resource->health > attack){
                            health += attack;
                        }else{
                            health += resource->health;
                        }
                    }
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
