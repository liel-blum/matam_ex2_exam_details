#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"
#include <vector>
#include <memory>


namespace mtm {
    class Soldier : public Character {
        static const int MOVEMENT_RANGE = 3;
        static const int AMMO_ON_RELOAD = 3;
        static const int AMMO_ATTACK_COST = 1;
        static const char CROSSFITTERS_SIGN = 's';
        static const char POWER_LIFTERS_SIGN = 'S';
        static const int COLLATERAL_DAMAGE_RANGE_FACTOR = 3;
        static const int COLLATERAL_DAMAGE_FACTOR = 2;
    public:
        ~Soldier() override= default;
        Soldier(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team,
                                                                                   MOVEMENT_RANGE, AMMO_ON_RELOAD,
                                                                                   AMMO_ATTACK_COST,
                                                                                   CROSSFITTERS_SIGN, POWER_LIFTERS_SIGN) {};

        bool isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                           std::shared_ptr<Character> target) override;

        void attack(std::shared_ptr<Character> target, bool is_main_target) override;

        Character* clone() const override;

        std::vector<std::shared_ptr<GridPoint>> getAttackTargets(const GridPoint &dst_coordinates) override;
    };


}
#endif //SOLDIER_H
