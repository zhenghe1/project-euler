/* What is the largest prime factor of the number 600851475143 ? */

#include "euler_interface.h"

class P003 : public EI {
    public:
        virtual std::string exec() {
            unsigned long long number = 600851475143;
            unsigned short divisor = 2;
            unsigned short largestDivisor = 0;

            while(number != 1) {
                if(number % divisor != 0) {
                    ++divisor;
                } else {
                    number /= divisor;
                    if(largestDivisor < divisor) {
                        largestDivisor = divisor;
                    }
                    divisor = 2;
                }
            }
            return std::to_string(largestDivisor);
            
        }
        
};