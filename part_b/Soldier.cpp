
#include "Soldier.h"
#include <vector>
#include <memory>

namespace mtm{
    bool Soldier::isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates){
        if(src_coordinates.row!=dst_coordinates.row || src_coordinates.col!=dst_coordinates.col ||
        GridPoint::distance(src_coordinates,dst_coordinates)>range){
            return false;
        }
        return true;
    }

    void Soldier::attack(const std::vector<std::vector<std::shared_ptr<Character>>>& board,const GridPoint & src_coordinates, const GridPoint & dst_coordinates) {

    }
}
