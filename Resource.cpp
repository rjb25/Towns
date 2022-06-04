#include "Resource.h"
#include "Entity.h"
#include "Manager.h"
#include <iostream>

Resource::Resource(Manager* manager, int health)
: Entity(manager, health)
{
    //Maybe set regen here?
}

void Resource::Act(bool print){
    Entity::Act(print);
    //Have plant Ai for... being eaten? Maybe seed/mate decisions
    
}
