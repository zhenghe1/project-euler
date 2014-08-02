/* Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product? */
#include "euler_interface.h"
#include <deque>

class P008 : public EI {
    public:
        virtual std::string exec() {
            const std::string NUMBER = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
            const unsigned int SIZE = 13;
            unsigned long product = 1;
            unsigned long tempProd;
            
            // Use a double ended queue to create a box of 13 adjacent numbers
            // Box moves one digit at a time to the right. This way, it avoids calculating all 13 digits per iteration and only accounts for a single digit per iteration.
            std::deque<unsigned short> adjNum;
            std::string::const_iterator strIt = NUMBER.begin();
            for(unsigned int i = 0; i < SIZE; i++) {
                unsigned int num = *strIt - '0';
                adjNum.push_back(num);
                product *= num;
                ++strIt;
            }
            tempProd = product;
            
            // Divide the product when popping, multiply product with pushing values
            // Also account for if the popped value is 0 to avoid divide by 0 error
            while(strIt != NUMBER.end()) {
                unsigned int poppedNum = adjNum.front();
                adjNum.pop_front();
                unsigned int num = *strIt - '0';
                adjNum.push_back(num);
                if(poppedNum == 0) {
                    tempProd = 1;
                    std::deque<unsigned short>::iterator dIt = adjNum.begin();
                    while(dIt != adjNum.end()) {
                        tempProd *= *dIt;
                        ++dIt;
                    }
                } else {
                    tempProd /= poppedNum;
                    tempProd *= num;
                }
                if(product < tempProd) {
                    product = tempProd;
                }
                ++strIt;
            }
            
            return std::to_string(product);
        }
};