#ifndef CREATURE_H
#define CREATURE_H
class Entity;
class Manager;
class Creature : public Entity 
{
    public:
        int attack = 1;
        Creature(Manager * manager, int health, int attack);
        void Act(bool print);
};
#endif
