
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm {
    class Exception : public std::exception {};
    class IllegalArgument : public std::exception {};
    class IllegalCell : public std::exception {};
    class CellEmpty : public std::exception {};
    class MoveTooFar : public std::exception {};
    class CellOccupied : public std::exception {};
    class OutOfRange : public std::exception {};
    class OutOfAmmo : public std::exception {};
    class IllegalTarget : public std::exception {};
}
#endif //EXCEPTIONS_H
