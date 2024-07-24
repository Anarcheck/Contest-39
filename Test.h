#include "Solution.h"
#include <cstdio>

class Test
{
    Solution *sol;
    public:
    Test(Solution* sol) 
    {
        this->sol=sol;
    }
    ~Test()
    {
        this->sol=nullptr;
    }
    void create_test();
};