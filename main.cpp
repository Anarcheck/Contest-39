
#include "Test.h"
#include <iostream>
int main()
{
    /* int SizeOfHalf,numeral_system;
    std::cout<<"Enter numeral system"<<std::endl;
    std::cin>>numeral_system;
    std::cout<<"Enter size of half ticket"<<std::endl;
    std::cin>>SizeOfHalf;
    Solution sol(SizeOfHalf, numeral_system);
    sol.optimized_alg();
    std::cout<<"Number of steps is "<< sol.step_count<<std::endl;
    std::cout<<"Exec time is "<<sol.execution_time.count()<<std::endl;
    sol.unoptimized_alg();
    std::cout<<"Number of steps is "<< sol.step_count<<std::endl;
    std::cout<<"Exec time is "<<sol.execution_time.count()<<std::endl; */
    Solution sol(0, 0);
    Test test(&sol);
    test.create_test();
    return 0;
}