
#include "Sniper.h"
#include <cmath>

namespace mtm{
    bool Sniper::isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates){
        int distance = GridPoint::distance(src_coordinates,dst_coordinates);
        if(distance>range || distance<ceil(static_cast<double>(range)/2)){
            return false;
        }
        return true;
    }



    /*void Sniper::attack(const std::vector<std::vector<std::shared_ptr<Character>>>& board,const GridPoint & src_coordinates, const GridPoint & dst_coordinates) {
        std::shared_ptr<Character> victim = board.at(dst_coordinates.row).at(dst_coordinates.col);
        if(victim->getTeam()==this->team){
            return;
        }
        else{

        }
    }*/
}
