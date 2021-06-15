
#include "Medic.h"

namespace mtm{
    bool Medic::isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                              std::shared_ptr<Character> target) {
        if(!target || src_coordinates==dst_coordinates){
            return false;
        }
        return true;
    }

    void Medic::attack(std::shared_ptr<Character> target, bool is_main_target) {
        if(is_main_target ){
            int damage=this->power;
            if(target->getTeam()!=this->team){
                damage*=-1;
                this->ammo-=AMMO_ATTACK_COST;
            }
            target->getAttacked(damage);
        }
    }
    Character* Medic::clone() const {
        return new Medic(*this);
    }
}
