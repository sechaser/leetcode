#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int solver(std::vector<int>& nums, int beg, int end)
{
    std::vector<int> dp(end-beg, 0);
    dp[0] = nums[beg];
    dp[1] = std::max(nums[beg], nums[beg + 1]);

    for(int i = beg + 2; i < end; ++ i)
        dp[i-beg] = std::max(dp[i-beg-2]+nums[i], dp[i-beg-1]);

    return dp[dp.size()-1];
}

int rob(std::vector<int>& nums)
{
    if(nums.size() <= 1)
        return nums.empty()? 0 : nums[0];

    if(nums.size() == 2)
        return std::max(nums[0], nums[1]);

    int withoutBeg = solver(nums, 1, nums.size());
    int withoutEnd = solver(nums, 0, nums.size() - 1);
    std::cout<<withoutBeg<<" "<<withoutEnd<<std::endl;

    return std::max(withoutBeg, withoutEnd);
}

int main()
{
    std::vector<int> nums{1,2,3,4};
    std::cout<<rob(nums)<<std::endl;

    system("pause");
    return 0;
}

