#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//int rob(std::vector<int>& nums)
//{
//    if(nums.size() <= 1)
//        return nums.empty()? 0 : nums[0];

//    int n = nums.size();
//    std::vector<int> dp(n, 0);

//    dp[0] = nums[0];
//    dp[1] = std::max(nums[0], nums[1]);

//    for(int i = 2; i < nums.size(); ++ i)
//        dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);

//    return dp[n-1];
//}

int rob(std::vector<int>& nums)
{
    int a = 0,  b = 0;
    for(int i = 0; i < nums.size(); ++ i)
    {
        if(i % 2)
        {
            a += nums[i];
            a = std::max(a, b);
        }
        else
        {
            b += nums[i];
            b = std::max(a, b);
        }
    }

    return std::max(a, b);
}


int main()
{
    std::vector<int> nums{5, 3, 3, 8};
    std::cout<<rob(nums)<<std::endl;

    system("pause");
    return 0;
}

