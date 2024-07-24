#include "Test.h"
void Test::create_test()
{
    FILE *f1=fopen("unopt_out.txt","a");
    FILE *f2=fopen("opt_out.txt","a");
    
    fprintf(f1,"d,n,steps,exec_time\n");
    fprintf(f2,"d,n,steps,exec_time\n");
    
    for (int i = 2; i < 11; i++)
    {
        for (int j = 2; j < 13-i; j++)
        {
            sol->set_numeral_system(i);
            sol->set_size_of_half(j);
            sol->unoptimized_alg();
            fprintf(f1,"%d,%d,%llu,%lld\n", i, j, sol->step_count, sol->execution_time.count());
            sol->optimized_alg();
            fprintf(f2,"%d,%d,%llu,%lld\n", i, j, sol->step_count, sol->execution_time.count());
        }
        
    }
    
    fclose(f1);
    fclose(f2);
    
}