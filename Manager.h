#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
class Entity;
class Creature;
class Resource;
class Manager {
    public:
        std::vector<std::vector<Entity*>> entities;
        std::vector<Creature*> creatures;
        std::vector<Resource*> resources;
        Manager(int numCreatures, int numResources);
        void CleanDead();
};
#endif
