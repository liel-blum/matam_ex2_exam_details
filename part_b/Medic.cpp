
#include "Medic.h"

namespace mtm{
    bool Medic::isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates){
        if(GridPoint::distance(src_coordinates,dst_coordinates)>range){
            return false;
        }
        return true;
    }
}
