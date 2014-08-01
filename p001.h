/* Find the sum of all the multiples of 3 or 5 below 1000. */

#include "euler_interface.h"

class P001 : public EI {
    public:
        virtual std::string exec() {
            unsigned int sum = 0;
            const unsigned int MAX = 1000;
            
            // Loop through all multiples of 3, ignoring those that are multiples of 5
            for(unsigned int i = 3; i < MAX; i+=3) {
                if(i % 5 != 0) {
                    sum += i;
                }
            }
            
            // Loop through all multiples of 5
            for(unsigned int i = 5; i < MAX; i+=5) {
                sum += i;
            }
            
            return std::to_string(sum);
        }
};