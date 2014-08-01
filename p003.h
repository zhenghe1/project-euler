/* What is the largest prime factor of the number 600851475143 ? */

#include "euler_interface.h"
#include <unordered_set>

class P003 : public EI {
    public:
        virtual std::string exec() {
            unsigned long long number = 600851475143;
            unsigned short divisor = 2;
            unsigned short largestDivisor = 0;
            unsigned short largestPrime = 0;
            
            while(number != 1) {
                if(number % divisor != 0) {
                    ++divisor;
                } else {
                    number /= divisor;
                    if(largestDivisor < divisor) {
                        largestDivisor = divisor;
                        if(isPrime(largestDivisor) && largestPrime < largestDivisor) {
                            largestPrime = largestDivisor;
                        }
                    }
                    divisor = 2;
                }
            }
            return std::to_string(largestPrime);
        }
        
        bool isPrime(const unsigned short num) {
            if(num == 1) {
                return false;
            } else if(num % 2 == 0 && num != 2) {
                return false;        
            } else {
                unsigned short divisor = num - 1;
                while(divisor > 1) {
                    if(num % divisor == 0) {
                        return false;
                    }
                    divisor -= 2;
                }
                return true;
            }
        }
};