/* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */
#include "euler_interface.h"

class P006 : public EI {
    public:
        virtual std::string exec() {
            const unsigned short MAX = 100;
            return std::to_string(sqOfSum(MAX) - sumOfSq(MAX));
        }
        
        unsigned int sumOfSq(const unsigned short n) {
            return ((n * (n + 1) * (2 * n + 1)) / 6);
        }
        
        unsigned int sqOfSum(const unsigned short n) {
            return pow(((n * (n + 1)) / 2), 2);
        }
};