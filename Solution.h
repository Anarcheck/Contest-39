#include <chrono>
#include <vector>
#include <cmath>


class Solution
{
    int SizeOfHalf;
    int numeral_system;
    void increase_vector(std::vector<int>& vect, int numeral_system);
    int calc_sum_of_vector(std::vector<int>& vect);
    unsigned long long D(int k, int n, int numeral_system);
    public:
    std::chrono::nanoseconds execution_time;
    unsigned long long int step_count;
    Solution(int SizeOfHalf=0, int numeral_system=0)
    {
        this->SizeOfHalf=SizeOfHalf;
        this->numeral_system=numeral_system;
    }
    void set_size_of_half(int n)
    {
        this->SizeOfHalf=n;
    };
    void set_numeral_system(int d)
    {
        this->numeral_system=d;
    }
    unsigned long long unoptimized_alg();
    unsigned long long optimized_alg();
};