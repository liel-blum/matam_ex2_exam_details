#include "Character.h"
#include <vector>
#include <memory>

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

    bool Character::isAttackInRange(int distance) {
        if(distance>range){
            return false;
        }
        return true;
    }

    bool Character::checkEnoughAmmo() {
        if(this->ammo-this->ammo_attack_cost>=0){
            return true;
        }
        return false;
    }

    bool Character::isDead(){
        return this->health<=0;
    }

    char Character::getCharacterSign(){
        return this->team==POWERLIFTERS? this->power_lifters_sign: cross_fitters_sign;
    }

    std::vector<std::shared_ptr<GridPoint>> Character::getAttackTargets(const GridPoint &dst_coordinates) {
        std::vector<std::shared_ptr<GridPoint>> attack_targets;
        attack_targets.push_back(std::make_shared<GridPoint>(dst_coordinates));
        return attack_targets;
    }

    void Character::getAttacked(int attack_damage) {
        this->health+=attack_damage;
    }
}