#include "Solution.h"


void Solution::increase_vector(std::vector<int>& vect, int numeral_system)
{
    int len=vect.size();
    vect[0]++;
    for (int i = 0; i < len; i++)
    {
        //this->step_count++;
        if (i==len-1 && vect[i]==numeral_system) return;

        if(vect[i]==numeral_system) 
        {
            vect[i]-=numeral_system;
            vect[i+1]++;
        }
    }
}

int Solution::calc_sum_of_vector(std::vector<int>& vect)
{
    int sum=0;
    int len=vect.size();
    for(int i=0; i<len; i++)
    {
        //this->step_count++;
        sum+=vect[i];
    }
    return sum;
}

unsigned long long Solution::D(int k, int n, int numeral_system)
{
    this->step_count++;
    if(n==0)
    {
        if(k==0) return 1;
        else return 0;
    }

    unsigned long long res=0;
    for (int i = 0; i < numeral_system; i++)
    {
        res+=D(k-i,n-1,numeral_system);
    }

    return res;
}

unsigned long long Solution::unoptimized_alg()
{
    this->step_count=0;
    std::vector<int> FirstHalf(SizeOfHalf, 0), SecondHalf(SizeOfHalf, 0);
    int num_of_numbers=pow(numeral_system, SizeOfHalf);
    unsigned long long count=0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<num_of_numbers;i++)
    {
        int sum1=calc_sum_of_vector(FirstHalf);
        fill(SecondHalf.begin(),SecondHalf.end(),0);
        for(int j=0; j<num_of_numbers;j++)
        {
            this->step_count++;
            int sum2=calc_sum_of_vector(SecondHalf);
            if (sum1 == sum2) count++;
            increase_vector(SecondHalf, numeral_system);
        }
        increase_vector(FirstHalf, numeral_system);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    this->execution_time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return count;
}

unsigned long long Solution::optimized_alg()
{
    this->step_count=0;
    int k=(numeral_system-1)*SizeOfHalf;
    int n=2*SizeOfHalf;
    auto start = std::chrono::high_resolution_clock::now();
    unsigned long long ans=D(k,n,numeral_system);
    auto stop = std::chrono::high_resolution_clock::now();
    this->execution_time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return ans;
}