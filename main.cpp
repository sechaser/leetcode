#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int firstMissiongPositive(std::vector<int>& nums)
{
    if(nums.empty())
        return 1;

    std::sort(nums.begin(), nums.end());
    size_t i = 0;

    while(i != nums.size())
    {
        if(nums[i] < 0)
            ++ i;
        else
            break;
    }

    if(nums[i] <= 1)
    {
        size_t j = i + 1;
        while(j != nums.size())
        {
            if((nums[j] == nums[j-1] + 1 ) || (nums[j] == nums[j - 1]))
            {
                ++ j;
                continue;
            }
            else
                break;
        }

        return nums[j-1]+1;
    }
    else
        return 1;
}

int main()
{
    std::vector<int> nums = {1};
    int res = firstMissiongPositive(nums);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

