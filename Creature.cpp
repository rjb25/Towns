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
    //AI
    int action = std::rand()%3;
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
            {
            std::vector<Entity*> creatures = manager->Exclude(manager->GetCreatures(manager->entities), priority);
            if(creatures.size() > 0){
                int target = std::rand()%creatures.size();
                Creature* creature = dynamic_cast<Creature*>(creatures[target]);
                health -= creature->attack;
                creature->health -= attack;
                health += attack;
            }
            break;
            }
            //Mate
        case 2:
            {
                std::vector<Entity*> creatures = manager->Exclude(manager->GetCreatures(manager->entities), priority);
                if(creatures.size() > 0){
                    int target = std::rand()%creatures.size();
                    Entity* creature = creatures[target];
                    if(creature->health > 0 && health > 15){
                        health-=10;
                        manager->SpawnCreature();
                    }
                }
            break;
            }
        default:
            std::cout << "Undefined choice" << std::endl;
            break;
    }
}
