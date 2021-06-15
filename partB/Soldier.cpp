
#include "Soldier.h"
#include <vector>
#include <memory>
#include <cmath>

namespace mtm{
    bool Soldier::isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                                std::shared_ptr<Character> target) {
        if(src_coordinates.row!=dst_coordinates.row && src_coordinates.col!=dst_coordinates.col){
            return false;
        }
        return true;
    }

    std::vector<std::shared_ptr<GridPoint>> Soldier:: getAttackTargets(const GridPoint &dst_coordinates){
        std::vector<std::shared_ptr<GridPoint>> attack_targets;
        int collateral_damage_range = ceil(static_cast<double>(range) / COLLATERAL_DAMAGE_RANGE_FACTOR);
        for(int i=-collateral_damage_range; i<=collateral_damage_range*2; i++){
            for(int j=-collateral_damage_range; j<=collateral_damage_range*2; j++){
                GridPoint point_to_add(dst_coordinates.row+i,dst_coordinates.col+j);
                if(GridPoint::distance(point_to_add, dst_coordinates)<=collateral_damage_range){
                    attack_targets.push_back(std::make_shared<GridPoint>(point_to_add));
                }

            }
        }
        return attack_targets;
    }

    void Soldier::attack(std::shared_ptr<Character> target, bool is_main_target){
        int damage = ceil(static_cast<double>(power) / COLLATERAL_DAMAGE_FACTOR);
        if(is_main_target){
            this->ammo-=AMMO_ATTACK_COST;
            damage = this->power;
        }
        if(target && target->getTeam()!= this->team){
            target->getAttacked(-1*damage);
        }
    }

    Character* Soldier::clone() const {
        return new Soldier(*this);
    }
}
