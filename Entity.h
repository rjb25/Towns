#ifndef ENTITY_H
#define ENTITY_H
#include "Manager.h"

class Entity {
    public:
        Manager * manager;
        int health;
        Entity(Manager * manager, int health);
        void Act(bool print);
};
#endif
