#include "Character.h"

namespace mtm{
    bool Character::isValidMove(int distance){
        if(distance>movement_range){
            return false;
        }
        return true;
    }

    Team Character::getTeam(){
        return this->team;
    }

    void  Character::reloadAmmo(){
        this->ammo+=this->ammo_on_reload;
    }

    char Character::getCharacterSign(){
        return this->team==POWERLIFTERS? this->power_lifters_sign: cross_fitters_sign;
    }

    void Character::updateHealthAfterAttack(){

    }
}