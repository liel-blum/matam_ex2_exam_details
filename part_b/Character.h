//
// Created by lielb on 12/06/2021.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"

namespace mtm {
    class Character {
    protected:
        int health;
        int ammo;
        int range;
        int power;
        Team team;
    public:
        Character(int health, int ammo, int range, int power, Team team): health(health), ammo(ammo), range(range),
        power(power), team(team){};
        Character(const Character &character):health(character.health), ammo(character.ammo), range(character.range),
        power(character.power), team(character.team){};
        virtual ~character() = 0;
        virtual get_attacked()=0;
        virtual attack()=0;
        virtual load_ammo()=0;
    };
}

#endif //CHARACTER_H
