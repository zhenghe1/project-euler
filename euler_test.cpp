#include "all_headers.h"
#include <assert.h>
#include <memory>

/* Uses the base class EI to get answers to all the derived classes that use the interface */
std::string print(std::unique_ptr<EI> problem, int problemNumber) {
    std::string answer = problem->exec();
    std::cout << "Problem: " << problemNumber << "  Solution: " << answer << std::endl;
    return answer;
}

int main() {
    typedef std::unique_ptr<EI> EIUPtr;
    std::cout << "-----Starting Project Euler Tests-----" << std::endl;
    int count = 0;
    print(EIUPtr(new P001()), ++count);
    print(EIUPtr(new P002()), ++count);
    print(EIUPtr(new P003()), ++count);
    print(EIUPtr(new P004()), ++count);
    print(EIUPtr(new P005()), ++count);
    print(EIUPtr(new P006()), ++count);
    print(EIUPtr(new P007()), ++count);
    print(EIUPtr(new P008()), ++count);
    print(EIUPtr(new P009()), ++count);
    std::cout << "-----Completed " << count << " tests-----" << std::endl;
}