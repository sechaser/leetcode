#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::string> summaryRanges(std::vector<int>& nums)
{
    std::vector<std::string> res;
    if(nums.empty())
        return res;

    int start = 0;
    for(int i = 1; i < nums.size(); ++ i)
    {
        if((nums[i] - nums[i-1]) != 1)
        {
            std::string s;
            if(i - start > 1)
                s = std::to_string(nums[start]) + "->" + std::to_string(nums[i-1]);
            else
                s = std::to_string(nums[start]);
            res.push_back(s);
            start = i;
        }
    }

    if(start == nums.size() - 1)
    {
        std::string s = std::to_string(nums[start]);
        res.push_back(s);
    }
    else
    {
        std::string s = std::to_string(nums[start]) + "->" + std::to_string(nums[nums.size()-1]);
        res.push_back(s);
    }

    return res;
}


int main()
{
    std::vector<int> nums{0,2, 4,8};
    std::vector<std::string> res = summaryRanges(nums);

    for(int i = 0; i < res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

