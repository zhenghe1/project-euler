/* What is the 10,001st prime number? */
#include "euler_interface.h"

class P007 : public EI {
    public:
        virtual std::string exec() {
            unsigned int count = 1;
            unsigned int prime = 1;
            // start from 3
            while(count < 10001) {
                prime += 2;
                if(isPrime(prime)) {
                    count++;
                }
            }
            
            return std::to_string(prime);
        }
        
        bool isPrime(const unsigned int n) {
            if(n == 0 || n == 1) {
                return false;
            } else if(n == 2) {
                return true;
            } else {
                if(n % 2 == 0) {
                    return false;
                }
                for(unsigned int i = 3; i <= sqrt(n); i += 2) {
                    if(n % i == 0) {
                        return false;
                    }
                }
                return true;
            }
        }
};