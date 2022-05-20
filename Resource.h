#ifndef RESOURCE_H
#define RESOURCE_H
#include "Entity.h"
#include "Manager.h"

class Resource : public Entity
{
    public:
        Resource(Manager * manager, int health);
        void Act(bool print);
};
#endif
