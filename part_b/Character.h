//
// Created by lielb on 12/06/2021.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"
#include <vector>
#include <memory>

namespace mtm {
    class Character {
    protected:
        int health;
        int ammo;
        int range;
        int power;
        Team team;
        const int movement_range;
        const int ammo_on_reload;
        const int ammo_attack_cost;
        const char cross_fitters_sign;
        const char power_lifters_sign;
    public:
        Character(int health, int ammo, int range, int power, Team team, int movement_range, int ammo_on_reload,
                  int ammo_attack_cost, char cross_fitters_sign, char power_lifters_sign) : health(health), ammo(ammo),
                                                                                          range(range),
                                                                                          power(power), team(team),
                                                                                          movement_range(
                                                                                                  movement_range),
                                                                                          ammo_on_reload(
                                                                                                  ammo_on_reload),
                                                                                          ammo_attack_cost(
                                                                                                  ammo_attack_cost),
                                                                                          cross_fitters_sign
                                                                                                  (cross_fitters_sign),
                                                                                          power_lifters_sign
                                                                                                  (power_lifters_sign) {};

        Character(const Character &character) : health(character.health), ammo(character.ammo), range(character.range),
                                                power(character.power), team(character.team),
                                                movement_range(character.movement_range),
                                                ammo_on_reload(character.ammo_on_reload),
                                                ammo_attack_cost(character.ammo_attack_cost), cross_fitters_sign
                                                (character.cross_fitters_sign), power_lifters_sign(character.power_lifters_sign) {};

        virtual ~Character(){};

        virtual Character* clone() const = 0;

        virtual std::vector<std::shared_ptr<GridPoint>>
        getAttackTargets(const GridPoint &dst_coordinates);

        virtual bool isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                                   std::shared_ptr<Character> target) = 0;

        void getAttacked(int attack_damage) ;

        bool isValidMove(int distance);

        bool isDead();

        virtual bool isAttackInRange(int distance);

        virtual void attack(std::shared_ptr<Character> target, bool is_main_target) =0;

        bool checkEnoughAmmo();

        Team getTeam();

        char getCharacterSign();

        void reloadAmmo();
    };
}

#endif //CHARACTER_H
