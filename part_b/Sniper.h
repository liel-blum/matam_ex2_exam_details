//
// Created by lielb on 12/06/2021.
//

#ifndef SNIPER_H
#define SNIPER_H

#include "Character.h"
const int MOVEMENT_RANGE = 4;
const int AMMO_ON_RELOAD = 2;
const int AMMO_ATTACK_COST = 1;
namespace mtm {
    class Sniper: public Character{

        int number_of_successful_hits;
    public:
        Sniper(int health, int ammo, int range, int power, Team team): Character(health, ammo, range, power, team,MOVEMENT_RANGE,AMMO_ON_RELOAD,AMMO_ATTACK_COST), number_of_successful_hits(0) {}
        bool isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) override;
        void attack(const std::vector<std::vector<std::shared_ptr<Character>>>& board,const GridPoint & src_coordinates, const GridPoint & dst_coordinates) override;
    };
}
#endif //SNIPER_H