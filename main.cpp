#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//int missingNumber(std::vector<int>& nums)
//{
//    int sum1 = 0;
//    int sz = nums.size();
//    for(int i = 1; i <= sz; ++ i)
//        sum1 += i;

//    int sum2 = 0;
//    for(int i = 0; i < sz; ++ i)
//        sum2 += nums[i];

//    return sum1-sum2;
//}


int missingNumber(std::vector<int>& nums)
{
    int sz = nums.size();
    int res = 0;
    for(int i = 0; i <= sz; ++ i)
        res ^= i;

    for(int i = 0; i < sz; ++ i)
        res ^= nums[i];

    return res;
}

int main()
{
    std::vector<int> nums{0,1,3};
    std::cout<<missingNumber(nums)<<std::endl;

    system("pause");
    return 0;
}

