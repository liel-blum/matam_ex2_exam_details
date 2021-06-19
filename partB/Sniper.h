#ifndef SNIPER_H
#define SNIPER_H

#include "Character.h"

namespace mtm {
    class Sniper : public Character{
        int number_of_successful_hits;

        //STATIC CONSTS
        static const int MOVEMENT_RANGE = 4;
        static const int AMMO_ON_RELOAD = 2;
        static const int AMMO_ATTACK_COST = 1;
        static const char CROSSFITTERS_SIGN = 'n';
        static const char POWER_LIFTERS_SIGN = 'N';
        static const int MIN_ATTACK_RANGE_FACTOR = 2;
        static const int SUCCESSFUL_HITS_FOR_DOUBLE = 3;
        static const int DOUBLE_ATTACK = 2;

    public:
       /**
        * Constructor of Sniper
         * @param health points
         * @param ammo points
         * @param range attack
         * @param power points
         * @param team - POWERLIFTERS or CROSSFITTERS
        */
        Sniper(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team,
                                                                                  MOVEMENT_RANGE, AMMO_ON_RELOAD,
                                                                                  AMMO_ATTACK_COST,
                                                                                  team == CROSSFITTERS ?
                                                                                  CROSSFITTERS_SIGN:
                                                                                  POWER_LIFTERS_SIGN),
                                                                        number_of_successful_hits(0) {}
        /**
         * Destructor of Sniper
         */
        ~Sniper() override =default;

        /**
         * check if Sniper can attack target
         * @param src_coordinates of attacker
         * @param dst_coordinates of potential character to attack
         * @param target - potential character to attack
         * @return if target legal
         */
        bool isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                           std::shared_ptr<Character> target) override;

        /**
         * Check if target is in attack's range of Sniper
         * @param distance between attacker's cell to target's cell
         * @return if Sniper can attack target
         */
        bool isAttackInRange(int distance) override;

        /**
         * Attack target
         * @param target to attack
         * @param is_main_target - if target is placed in destination coordinates
         */
        void attack(std::shared_ptr<Character> target, bool is_main_target) override;

        /**
         * Clone Sniper
         * @return new instance of Sniper
         */
        Character* clone() const override;

    };
}
#endif //SNIPER_H