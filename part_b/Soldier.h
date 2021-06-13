#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"


namespace mtm {
    class Soldier : public Character {
        static const int MOVEMENT_RANGE = 3;
        static const int AMMO_ON_RELOAD = 3;
        static const int AMMO_ATTACK_COST = 1;
        static const char CROSSFITTERS_SIGN = 's';
        static const char POWER_LIFTERS_SIGN = 'S';
    public:
        Soldier(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team,
                                                                                   MOVEMENT_RANGE, AMMO_ON_RELOAD,
                                                                                   AMMO_ATTACK_COST) {};

        bool isAttackInRange(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) override;

        void attack(const std::vector<std::vector<std::shared_ptr<Character>>> &board, const GridPoint &src_coordinates,
                    const GridPoint &dst_coordinates) override;
    };
}
#endif //SOLDIER_H
