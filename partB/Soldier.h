#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"
#include <vector>
#include <memory>


namespace mtm {
    class Soldier : public Character {

        //STATIC CONSTS
        static const int MOVEMENT_RANGE = 3;
        static const int AMMO_ON_RELOAD = 3;
        static const int AMMO_ATTACK_COST = 1;
        static const char CROSSFITTERS_SIGN = 's';
        static const char POWER_LIFTERS_SIGN = 'S';
        static const int COLLATERAL_DAMAGE_RANGE_FACTOR = 3;
        static const int COLLATERAL_DAMAGE_FACTOR = 2;
    public:
        /**
        * Constructor of Soldier
         * @param health points
         * @param ammo points
         * @param range attack
         * @param power points
         * @param team - POWERLIFTERS or CROSSFITTERS
        */
        Soldier(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team,
                                                                                   MOVEMENT_RANGE, AMMO_ON_RELOAD,
                                                                                   AMMO_ATTACK_COST,
                                                                                   team == CROSSFITTERS ?
                                                                                   CROSSFITTERS_SIGN: POWER_LIFTERS_SIGN) {};
        /**
        * Destructor of Soldier
        */
        ~Soldier() override= default;

        /**
         * check if Soldier can attack target
         * @param src_coordinates of attacker
         * @param dst_coordinates of potential character to attack
         * @param target - potential character to attack
         * @return if target legal
         */
        bool isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                           std::shared_ptr<Character> target) override;

        /**
         * Attack target
         * @param target to attack
         * @param is_main_target - if target is placed in destination coordinates
         */
        void attack(std::shared_ptr<Character> target, bool is_main_target) override;

        /**
         * Clone Soldier
         * @return new instance of Soldier
         */
        Character* clone() const override;

        /**
         * Return vector contains attack target and all possible targets around the target that soldier can attack
         * @param dst_coordinates - attack destination coordinates
         * @return Vector of shared pointers to GridPoint objects
         */
        std::vector<std::shared_ptr<GridPoint>> getAttackTargets(const GridPoint &dst_coordinates) override;
    };


}
#endif //SOLDIER_H
