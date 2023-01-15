#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
class Entity;
class Creature;
class Resource;
class Manager {
    public:
        std::vector<Entity*> creatures;
        std::vector<Entity*> resources;
        std::vector<Entity*> entities;
        Manager(int numCreatures, int numResources);

        void CleanDead(std::vector<Entity*> & group);
};
#endif
