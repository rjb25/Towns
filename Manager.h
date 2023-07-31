#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
class Entity;
class Creature;
class Resource;
class Manager {
    public:
        std::vector<Entity*> entities;
        Manager(int numCreatures, int numResources);
        int availablePriority = 0;
        void CleanDead();
        int Add();
        void Remove(int priority);
        void Act(bool log);
        std::vector<Entity*> GetResources(std::vector<Entity*> group);
        std::vector<Entity*> GetCreatures(std::vector<Entity*> group);
        std::vector<Entity*> Exclude(std::vector<Entity*> group, int priority);
        void SpawnCreature();
        void SpawnResource();
};
#endif
