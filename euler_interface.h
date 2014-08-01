/* An interface for all test problems so testing is easier. */

#ifndef EULER_INTERFACE_H
#define EULER_INTERFACE_H

#include <iostream>

class EI {
    public:
        virtual ~EI() {}
        virtual std::string exec() = 0;
};

#endif