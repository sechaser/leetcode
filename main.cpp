#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

int threeSumClosest(std::vector<int>& nums, int target)
{
    if(nums.size() < 3)
        return INT_MAX;

    int minDiff = INT_MAX;
    int l, r;
    std::sort(nums.begin(), nums.end());

    for(std::vector<int>::size_type i = 0; i != nums.size() - 2; ++ i)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        l = i + 1, r = nums.size() - 1;
        while(l < r)
        {
            int curDiff = target - (nums[i] + nums[l] + nums[r]);

            if(std::abs(curDiff) < std::abs(minDiff))
                minDiff = curDiff;

            if(curDiff == 0)
                break;
            else if(curDiff > 0)
                ++ l;
            else
                -- r;

//            if(curDiff == 0)
//                return target;

//            if(std::abs(curDiff) < std::abs(minDiff))
//                minDiff = curDiff;
//            else if(curDiff > 0)
//                ++ l;
//            else
//                -- r;
        }
    }

    return target - minDiff;
}

int main()
{
    std::vector<int> iv{0, 0, 0};
    int target = 1;

    int res = threeSumClosest(iv, target);
    std::cout<<res<<std::endl;

    return 0;
}

