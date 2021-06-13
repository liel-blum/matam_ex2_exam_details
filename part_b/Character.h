//
// Created by lielb on 12/06/2021.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"
#include "Game.h"

namespace mtm {
    class Character {
    protected:
        int health;
        int ammo;
        int range;
        int power;
        Team team;
        const int movement_range ;
        const int ammo_on_reload ;
        const int ammo_attack_cost ;
    public:
        Character(int health, int ammo, int range, int power, Team team,int movement_range,int ammo_on_reload,int ammo_attack_cost): health(health), ammo(ammo), range(range),
        power(power), team(team),movement_range(movement_range),ammo_on_reload(ammo_on_reload),ammo_attack_cost(ammo_attack_cost){};
        Character(const Character &character):health(character.health), ammo(character.ammo), range(character.range),
        power(character.power), team(character.team),,movement_range(character.movement_range),ammo_on_reload(character.ammo_on_reload),ammo_attack_cost(character.ammo_attack_cost){};
        virtual ~Character() = 0;
        virtual void attack(const std::vector<std::vector<std::shared_ptr<Character>>>& board,const GridPoint & src_coordinates, const GridPoint & dst_coordinates)=0;
        virtual bool isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)=0;
        virtual void getAttacked()=0;
        bool isValidMove(int distance);
        Team getTeam();
        void reloadAmmo();
        void updateHealthAfterAttack(int health_points_to_remove);
    };
}

#endif //CHARACTER_H
