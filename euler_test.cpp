#include "all_headers.h"
#include <assert.h>
#include <iostream>

/* Uses the base class EI to get answers to all the derived classes that use the interface */
std::string print(EI *problem, int problemNumber) {
    std::string answer = problem->exec();
    std::cout << "Problem: " << problemNumber << "  Solution: " << answer << std::endl;
    delete problem;
    return answer;
}

int main() {
    std::cout << "-----Starting Project Euler Tests-----" << std::endl;
    int count = 0;
    print(new P001(), ++count);
    print(new P002(), ++count);
    std::cout << "-----Completed " << count << " tests-----" << std::endl;
}