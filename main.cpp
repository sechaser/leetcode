#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int minSubArrayLen(int s, std::vector<int>& nums)
{
    int sz = nums.size(), start = 0, sum = 0, minLen = INT_MAX;

    for(int i = 0; i < sz; ++ i)
    {
        sum += nums[i];
        while(sum >= s)
        {
            minLen = std::min(minLen, i-start+1);
            sum -= nums[start];
            ++ start;
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    std::vector<int> nums{2,3,1,2,4,3};
    std::cout<<minSubArrayLen(7, nums)<<std::endl;

    system("pause");
    return 0;
}

