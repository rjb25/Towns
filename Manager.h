#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include "Entity.h"
#include "Creature.h"
#include "Resource.h"

class Manager {
    public:
        std::vector<std::vector<Entity*>> entities;
        std::vector<Creature*> creatures;
        std::vector<Resource*> resources;
        Manager(int numCreatures, int numResources);
        void CleanDead();
};
#endif
