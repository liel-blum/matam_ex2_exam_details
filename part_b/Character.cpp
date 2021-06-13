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
    void Character::updateHealthAfterAttack(){

    }
}