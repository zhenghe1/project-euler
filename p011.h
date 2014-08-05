/* What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid? */
/* 
 * Using dynamic programming - moving a 4x4 square and keeping track of 10 potential solutions
 * Square can only move down, right, and up, calculating the product of every possible set only once.
 * The products are kept in an array. Each combination of numbers within the current square is kept in a deque list.
 * When the square moves a unit, the product only needs to divide itself by the old number and multiply by the new.
 * NOTE: The calcProduct function is a little messy and can probably be made cleaner
 */
#include "euler_interface.h"
#include <vector>
#include <deque>

class P011 : public EI {
    public:
        virtual std::string exec() {
            const std::vector<std::vector<unsigned int> > numGrid = {
                                    {8, 2, 22, 97, 38, 15, 0, 4, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
                                    {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 0}, 
                                    {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
                                    {52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
                                    {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
                                    {24, 47, 32, 60, 99, 3, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
                                    {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
                                    {67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
                                    {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
                                    {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
                                    {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
                                    {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
                                    {86, 56, 0, 48, 35, 71, 89, 07, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
                                    {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
                                    {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
                                    {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
                                    {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
                                    {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
                                    {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
                                    {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}
                                   };
            const int LAST_ROW = numGrid.size();
            const int LAST_COL = numGrid[0].size();                       
            
            // 0 - 3 = columns
            // 4 - 7 = rows
            // 8 - 9 = \ diagonal, / diagonal
            std::array<unsigned int, 10> products = {1};
            std::vector<std::deque<unsigned int> > square(10);
            
            // Start at square [0,0], [0,3], [3,0], [3,3]
            // Markers for creating the 4x4 box
            int rowStart = 0; int rowEnd = 3;
            int colStart = 0; int colEnd = 3;
            // Calculate product and move box down one row to begin
            unsigned int product = init(numGrid, products, square, rowStart, rowEnd, colStart, colEnd);
            
            unsigned int direction = 1;
            while((rowEnd != LAST_ROW - 1 && colEnd != LAST_COL - 1) || (rowStart != 0 && colEnd != LAST_COL - 1)) {
                if(rowEnd == LAST_ROW - 1) { // box is on last row - move box right, then up
                    if(direction == 1) {
                        direction = 2;
                        colStart++;
                        colEnd++;
                    } else {             
                        direction = 3;
                        rowStart--;
                        rowEnd--;
                    }
                } else if(rowStart == 0) { // box is on top row - move box right, then down
                    if(direction == 3) {
                        direction = 2;
                        colStart++;
                        colEnd++;
                    } else {
                        direction = 1;
                        rowStart++;
                        rowEnd++;
                    }
                } else { // box is in the middle - move either down or up
                    if(direction == 1) {
                        rowStart++;
                        rowEnd++;
                    } else {
                        rowStart--;
                        rowEnd--;
                    }
                }
                calcProduct(numGrid, product, products, square, rowStart, rowEnd, colStart, colEnd, direction);
            }
            
            
            return std::to_string(product);
        }
        
        unsigned int init(const std::vector<std::vector<unsigned int> > numGrid, 
                                        std::array<unsigned int, 10> &products, 
                                        std::vector<std::deque<unsigned int> > &square,
                                        const int rowStart, const int rowEnd,
                                        const int colStart, const int colEnd) {
            unsigned int product = 0;
            for(int i = rowStart; i <= rowEnd; i++) {
                for(int j = colStart; j <= colEnd; j++) {
                    unsigned int num = numGrid[i][j];
                    square[i - rowStart + 4].push_back(num); // add to corresponding row in square
                    products[i - rowStart + 4] *= num;
                    if(i - rowStart == 0) { // on row 0
                        square[j - i].push_back(num); // add to corresponding column
                        products[j - i] *= num;
                        // add to diagonals
                        if(j - i == 0) {
                            square[8].push_back(num);
                            products[8] *= num;
                        } else if(j - i == 3) {
                            square[9].push_back(num);
                            products[9] *= num;
                        } 
                    } else if(i - rowStart == 1) { // row 1
                        square[j - i + 1].push_back(num);
                        products[j - i + 1] *= num;
                        if(j - i == -1) {
                            square[8].push_back(num);
                            products[8] *= num;
                        } else if(j - i == 2) {
                            square[9].push_back(num);
                            products[9] *= num;
                        }
                    } else if(i - rowStart == 2) { // row 2
                        square[j - i + 2].push_back(num);
                        products[j - i + 2] *= num;
                        if(j - i == -2) {
                            square[8].push_back(num);
                            products[8] *= num;
                        } else if(j - i == 1) {
                            square[9].push_back(num);
                            products[9] *= num;
                        }
                    } else if(i - rowStart == 3) { // row 3
                        square[j - i + 3].push_back(num);
                        products[j - i + 3] *= num;
                        if(j - i == -3) {
                            square[8].push_back(num);
                            products[8] *= num;
                        } else if(j - i == 0) {
                            square[9].push_back(num);
                            products[9] *= num;
                        }
                    }
                }
            }
            for(unsigned int prod : products) {
                if(product < prod) {
                    product = prod;
                }
            }
            return product;
        }
        
        // @params direction : 1 == down, 2 == right, 3 == up
        void calcProduct(const std::vector<std::vector<unsigned int> > numGrid, 
                                        unsigned int &product,
                                        std::array<unsigned int, 10> &products, 
                                        std::vector<std::deque<unsigned int> > &square,
                                        const int rowStart, const int rowEnd,
                                        const int colStart, const int colEnd,
                                        const unsigned int direction) {
            if(direction == 1) { // moving down a row
                // shift rows down
                for(int i = 4; i < 7; i++) {
                    products[i] = products[i+1];
                    square[i] = square[i+1];
                }
                // Calculate product for new row
                square[7].clear();
                products[7] = 1;
                for(int newCol = colStart; newCol <= colEnd; newCol++) {
                    products[7] *= numGrid[rowEnd][newCol];
                    square[7].push_back(numGrid[rowEnd][newCol]);
                }
                if(product < products[7]) {
                    product = products[7];
                }
                
                // Divide each column with old value and multiply with new value
                int newCol = colStart;
                for(int i = 0; i < 4; i++) {
                    int oldNum = square[i].front();
                    int newNum = numGrid[rowEnd][newCol++];
                    square[i].pop_front();
                    square[i].push_back(newNum);
                    if(oldNum == 0) {
                        products[i] = 1;
                        for(unsigned int colNum : square[i]) {
                            products[i] *= colNum;
                        }
                    } else {
                        products[i] /= oldNum; products[i] *= newNum;
                    }
                    if(product < products[i]) {
                        product = products[i];
                    }
                }
            } else if(direction == 2) { // moving right a column
                // shift columns right
                for(int i = 0; i < 3; i++) {
                    products[i] = products[i+1];
                    square[i] = square[i+1];
                }
                // calculate new column
                square[3].clear();
                products[3] = 1;
                for(int newRow = rowStart; newRow <= rowEnd; newRow++) {
                    products[3] *= numGrid[colEnd][newRow];
                    square[3].push_back(numGrid[colEnd][newRow]);
                }
                if(product < products[3]) {
                    product = products[3];
                }
                // Divide each row with old value and multiply with new value
                int newRow = rowStart;
                for(int i = 4; i < 8; i++) {
                    int oldNum = square[i].front();
                    int newNum = numGrid[colEnd][newRow++];
                    square[i].pop_front();
                    square[i].push_back(newNum);
                    if(oldNum == 0) {
                        products[i] = 1;
                        for(unsigned int colNum : square[i]) {
                            products[i] *= colNum;
                        }
                    } else {
                        products[i] /= oldNum; products[i] *= newNum;
                    }
                    if(product < products[i]) {
                        product = products[i];
                    }
                }
            } else if(direction == 3) { // moving up a row
                // shift rows up
                for(int i = 7; i > 4; i--) {
                    products[i] = products[i-1];
                    square[i] = square[i-1];
                }
                
                // Calculate product for new row
                square[4].clear();
                products[4] = 1;
                for(int newCol = colStart; newCol <= colEnd; newCol++) {
                    products[4] *= numGrid[rowStart][newCol];
                    square[4].push_back(numGrid[rowStart][newCol]);
                }
                if(product < products[4]) {
                    product = products[4];
                }
                
                // Divide each column with old value and multiply with new value
                int newCol = colStart;
                for(int i = 0; i < 4; i++) {
                    int oldNum = square[i].back();
                    int newNum = numGrid[rowStart][newCol++];
                    square[i].pop_back();
                    square[i].push_front(newNum);
                    if(oldNum == 0) {
                        products[i] = 1;
                        for(unsigned int colNum : square[i]) {
                            products[i] *= colNum;
                        }
                    } else {
                        products[i] /= oldNum; products[i] *= newNum;
                    }
                    if(product < products[i]) {
                        product = products[i];
                    }
                }
            }
            // calculate new diagonals \ and /
            products[8] = 1; products[9] = 1;
            square[8].clear(); square[9].clear();
            for(int i = 0; i < 4; i++) {
                products[8] *= numGrid[rowStart+i][colStart+i];
                square[8].push_back(numGrid[rowStart+i][colStart+i]);
            }
            if(product < products[8]) product = products[8];
            int j = 3;
            for(int i = 0; i < 4; i++) {
                products[9] *= numGrid[rowStart+i][colStart+j];
                square[9].push_back(numGrid[rowStart+i][colStart+j]);
                j--;
            }
            if(product < products[9]) product = products[9];
        }
        
};