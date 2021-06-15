//
// Created by lielb on 12/06/2021.
//

#ifndef SNIPER_H
#define SNIPER_H

#include "Character.h"


namespace mtm {
    class Sniper : public Character{
        static const int MOVEMENT_RANGE = 4;
        static const int AMMO_ON_RELOAD = 2;
        static const int AMMO_ATTACK_COST = 1;
        static const char CROSSFITTERS_SIGN = 'n';
        static const char POWER_LIFTERS_SIGN = 'N';
        static const int MIN_ATTACK_RANGE_FACTOR = 2;
        static const int SUCCESSFUL_HITS_FOR_DOUBLE = 3;
        static const int DOUBLE_ATTACK = 2;
        int number_of_successful_hits;
    public:
        ~Sniper() override =default;
        Sniper(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team,
                                                                                  MOVEMENT_RANGE, AMMO_ON_RELOAD,
                                                                                  AMMO_ATTACK_COST,
                                                                                  CROSSFITTERS_SIGN, POWER_LIFTERS_SIGN),
                                                                        number_of_successful_hits(0) {}

        bool isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                           std::shared_ptr<Character> target) override;

        bool isAttackInRange(int distance) override;

        void attack(std::shared_ptr<Character> target, bool is_main_target) override;

        Character* clone() const override;
    };
}
#endif //SNIPER_H