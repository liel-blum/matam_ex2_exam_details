
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm {
    class Exception : public std::exception {
    public:
        const char* what() const noexcept override;
        virtual const char* getError() const=0;
    };
    class IllegalArgument : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: IllegalArgument";
        }
    };
    class IllegalCell : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: IllegalCell";
        }
    };
    class CellEmpty : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: CellEmpty";
        }
    };
    class MoveTooFar : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: MoveTooFar";
        }
    };
    class CellOccupied : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: CellOccupied";
        }
    };
    class OutOfRange : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: OutOfRange";
        }
    };
    class OutOfAmmo : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: OutOfAmmo";
        }
    };
    class IllegalTarget : public Exception {
        const char* getError() const override{
            return "A game related error has occurred: IllegalTarget";
        }
    };
}
#endif //EXCEPTIONS_H
