
#include "Exceptions.h"
#include <string>
#include <cstring>
#include <iostream>


namespace mtm {
    const char * Exception::what() const noexcept {
       return getError();
    }
}