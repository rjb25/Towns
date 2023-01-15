#ifndef ENTITY_H
#define ENTITY_H
class Manager;
class Entity {
    public:
        Manager * manager;
        int health;
        int priority;
        Entity(Manager * manager, int health);
        virtual void Act(bool print);
};
#endif
