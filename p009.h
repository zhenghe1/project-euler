/* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
   Find the product abc. */
#include "euler_interface.h"


/*
    a + b + c = 1000
    a^2 + b^2 = c^2
    c = sqrt(a^2 + b^2)
    a + b + sqrt(a^2 + b^2) = 1000
    sqrt(a^2 + b^2) = 1000 - a - b
    a^2 + b^2 = (1000 - a - b)^2
    a^2 + b^2 = 1000000 - 1000a - 1000b - 1000a + a^2 +ab -1000b + ab + b^2
    a^2 + b^2 = 1000000 - 2000(a + b) + a^2 + 2ab + b^2
    0 = 1000000 - 2000(a + b) + 2ab
    0 = 1000000 - 2000a - 2000b + 2ab
    0 = 500000 - 1000a - 1000b + ab
    1000a - ab = 500000 - 1000b
    a(1000 - b) = 500000 - 1000b
    a = (500000 - 1000b) / (1000 - b)
*/
class P009 : public EI {
    public:
        virtual std::string exec() {
            unsigned short a;
            unsigned short b;
            unsigned short c;
            // since a < b < c, 1000/3 <= b <= 1000/2 or else sum will exceed 1000
            unsigned short bStart = 1000/3;
            unsigned short bEnd = 1000/2;
            
            for(unsigned short i = bStart; i < bEnd; i++) {
                if((500000 - 1000 * i) % (1000 - i) == 0) {
                    b = i;
                    a = (500000 - 1000 * i) / (1000 - i);
                    c = 1000 - a - b;
                    break;
                }
            }
            
            unsigned int product = a * b * c;
            return std::to_string(product);
        }
};