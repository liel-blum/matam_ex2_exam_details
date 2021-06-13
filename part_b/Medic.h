//
// Created by lielb on 12/06/2021.
//

#ifndef MEDIC_H
#define MEDIC_H

#include "Character.h"
const int MOVEMENT_RANGE = 5;
const int AMMO_ON_RELOAD = 5;
const int AMMO_ATTACK_COST = 1;
namespace mtm {
    class Medic: public Character{
    public:
        Medic(int health, int ammo, int range, int power, Team team): Character(health, ammo, range, power, team,MOVEMENT_RANGE,AMMO_ON_RELOAD,AMMO_ATTACK_COST) {}
        bool isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) override;
        void attack(const std::vector<std::vector<std::shared_ptr<Character>>>& board,const GridPoint & src_coordinates, const GridPoint & dst_coordinates) override;
    };
}
#endif //MEDIC_H