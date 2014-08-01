/* Find the largest palindrome made from the product of two 3-digit numbers. */
#include "euler_interface.h"
#include <algorithm>

class P004 : public EI {
    public:
        virtual std::string exec() {
            unsigned int prod = 0;
            unsigned int pal = 0;
            for(unsigned int i = 100; i < 1000; i++) {
                for(unsigned int j = i; j < 1000; j++) {
                    prod = i * j;
                    if(isPalindrome(prod)) {
                        if(pal < prod) {
                            pal = prod;
                        }
                    }
                }
            }
            return std::to_string(pal);
        }
        
        bool isPalindrome(const unsigned int number) {
            std::string s = std::to_string(number);
            std::string temp = s;
            std::reverse(s.begin(), s.end());
            if(temp == s) {
                return true;
            }
            return false;
        }
};