#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//***************************************Time:O(n)***********************************************
//int maxSubArray(std::vector<int>& nums)
//{
//    int res = INT_MIN, sum = -1;
//    size_t nums_sz = nums.size();

//    for(int i = 0; i != nums_sz; ++ i)
//    {
//        if(sum > 0)
//            sum += nums[i];
//        else
//            sum = nums[i];

//        if(sum > res)
//            res = sum;
//    }

//    return res;
//}


int maxSubArray(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;

    int global = nums[0];
    int local  = nums[0];

    for(int i = 1; i < nums.size(); ++ i)
    {
        local  = std::max(nums[i], local + nums[i]);
        global = std::max(local, global);
    }

    return global;
}



int main()
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<maxSubArray(nums)<<std::endl;

    system("pause");
    return 0;
}

