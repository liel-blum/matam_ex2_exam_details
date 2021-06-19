//
// Created by lielb on 12/06/2021.
//

#ifndef MEDIC_H
#define MEDIC_H

#include "Character.h"


namespace mtm {
    class Medic : public Character {

        //STATIC CONSTS
        static const int MOVEMENT_RANGE = 5;
        static const int AMMO_ON_RELOAD = 5;
        static const int AMMO_ATTACK_COST = 1;
        static const char CROSSFITTERS_SIGN = 'm';
        static const char POWER_LIFTERS_SIGN = 'M';
    public:

        /**
        * Constructor of Medic
         * @param health points
         * @param ammo points
         * @param range attack
         * @param power points
         * @param team - POWERLIFTERS or CROSSFITTERS
        */
        Medic(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team,
                                                                                 MOVEMENT_RANGE, AMMO_ON_RELOAD,
                                                                                 AMMO_ATTACK_COST,
                                                                                 team == CROSSFITTERS ?
                                                                                 CROSSFITTERS_SIGN:
                                                                                 POWER_LIFTERS_SIGN) {
        }

        //OVERRIDE FUNCTIONS
        /**
        * Destructor of Medic
        */
        ~Medic() override = default;

        /**
         * check if Medic can attack target
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
         * Clone Medic
         * @return new instance of Medic
         */
        Character* clone() const override;
    };
}
#endif //MEDIC_H