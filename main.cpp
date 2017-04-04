#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>



std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    std::vector<int> res;
    if(nums.empty())
    {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }

    int l = 0, r = nums.size() - 1;
    int m;
    while(l <= r)
    {
        m = (l + r) / 2;
        if(nums[m] == target)
        {
            int i = m - 1;
            while(i >= 0 && nums[i] == target)
                -- i;
            res.push_back(i+1);

            int j = m  + 1;
            while(j < nums.size() && nums[j] == target)
                ++ j;
            res.push_back(j-1);

            return res;
        }
        else if(nums[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }

    if(res.empty())
    {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
}


int main()
{
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;

    std::vector<int> res = searchRange(nums, target);
    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

