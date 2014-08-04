/* Find the sum of all the primes below two million. */
// Uses the sieve of eratosthenes algorithm
#include "euler_interface.h"

class P010 : public EI {
    public:
        virtual std::string exec() {
            const unsigned int MAX = 2000000;
            // 0 == unchecked, 1 == not prime
            char numbers[MAX] = {0};
            unsigned long sum = 0;
            
            for(unsigned int i = 2; i < MAX; i++) {
                if(numbers[i] == 0) {
                    sum += i;
                    // Marks all multiples of i as not a prime
                    for(unsigned int counter = 2; i*counter < MAX; counter++) {
                        numbers[i*counter] = 1;
                    }
                }
            }
            return std::to_string(sum);
        }
};