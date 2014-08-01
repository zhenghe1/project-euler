/* By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms. */

#include "euler_interface.h"

class P002 : public EI {
    public:
        virtual std::string exec() {
            const unsigned int MAX = 4000000;
            unsigned int currFib = 1;
            unsigned int newFib = 2;
            unsigned int sum = 0;
            
            while(newFib <= MAX) {
                unsigned int tempFib = newFib;
                if(newFib % 2 == 0) {
                    sum += newFib;
                }
                newFib += currFib;
                currFib = tempFib;
            }
            
            return std::to_string(sum);
        }
};