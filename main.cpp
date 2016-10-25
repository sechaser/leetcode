#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


int searchInsert(std::vector<int>& nums, int target)
{
    if(nums.empty())
        return 0;
    else
    {
        size_t nums_sz = nums.size();
        int l = 0, r = nums_sz - 1, m = l + (r - l)/2;

        while(l <= r)
        {
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
            {
                l = m + 1;
                m = l + (r - l)/2;
            }
            else
            {
                r = m - 1;
                m = l + (r - l)/2;
            }
        }

        return l;
    }
}

int main()
{
    std::vector<int> nums{1,3,5,6};
    int target = 0;
    int res = searchInsert(nums, target);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

