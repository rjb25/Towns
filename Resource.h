#ifndef RESOURCE_H
#define RESOURCE_H
class Manager;
class Entity;
class Resource : public Entity {
    public:
        Resource(Manager * manager, int health);
        void Act(bool print);
};
#endif
