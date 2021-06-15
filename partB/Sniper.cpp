
#include "Sniper.h"
#include <cmath>

namespace mtm {
    bool Sniper::isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                               std::shared_ptr<Character> target) {
        if (!target || target->getTeam() == this->team) {
            return false;
        }
        return true;
    }

    bool Sniper::isAttackInRange(int distance) {
        if (distance > range || distance < ceil(static_cast<double>(range) / MIN_ATTACK_RANGE_FACTOR)) {
            return false;
        }
        return true;
    }

    void Sniper::attack(std::shared_ptr<Character> target, bool is_main_target) {
        if(is_main_target){
            int damage=this->power;
            this->number_of_successful_hits ++;
            if(this->number_of_successful_hits%SUCCESSFUL_HITS_FOR_DOUBLE==0){
                damage*=DOUBLE_ATTACK;
            }
            target->getAttacked(-1*damage);
            this->ammo-=AMMO_ATTACK_COST;
        }
    }
    Character* Sniper::clone() const {
        return new Sniper(*this);
    }

}
