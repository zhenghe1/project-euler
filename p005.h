/* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20? */
/*
    Find the prime factorizations of all numbers from 1-20.
    Smallest prime is 2, largest is 17.
    For each prime factorization, find the max count of each prime from 1-20 in each factorization.
    Multiply the max count of primes together to obtain the solution
*/
#include "euler_interface.h"

class P005 : public EI {
    public:
        virtual std::string exec() {
            unsigned int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
            unsigned int maxPrimeCount[20] = {0};
            unsigned int tempPrimeCount[20] = {0};
            
            for(unsigned short i = 2; i <= 20; i++) {
                unsigned int number = i;
                unsigned int divisor = 2;
                while(number != 1) {
                    if(number % divisor == 0) {
                        number /= divisor;
                        tempPrimeCount[divisor]++;
                        divisor = 2;
                    } else {
                        divisor++;
                    }
                    
                    for(auto prime : primes) {
                        if(maxPrimeCount[prime] < tempPrimeCount[prime]) {
                            maxPrimeCount[prime] = tempPrimeCount[prime];
                        }
                    }
                }
                std::fill(tempPrimeCount, tempPrimeCount+20, 0);
            }
            
            unsigned int answer = 1;
            unsigned int index = 0;
            for(auto prime : primes) {
                answer *= pow(primes[index], maxPrimeCount[prime]);
                index++;
            }
            
            return std::to_string(answer);
        }
};