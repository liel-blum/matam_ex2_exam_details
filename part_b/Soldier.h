#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"
const int MOVEMENT_RANGE = 3;
const int AMMO_ON_RELOAD = 3;
const int AMMO_ATTACK_COST = 1;
namespace mtm {
class Soldier: public Character{
public:
    Soldier(int health, int ammo, int range, int power, Team team): Character(health, ammo, range, power, team,MOVEMENT_RANGE,AMMO_ON_RELOAD,AMMO_ATTACK_COST){};
    bool isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) override;
    void attack(const std::vector<std::vector<std::shared_ptr<Character>>>& board,const GridPoint & src_coordinates, const GridPoint & dst_coordinates) override;
};
}
#endif //SOLDIER_H
