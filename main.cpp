#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool search(std::vector<int>& nums, int target)
{
    if(nums.empty())
        return false;

    int sz = nums.size();
    int l = 0, r = sz - 1;
    int m;

    while(l <= r)
    {
        m = (l + r) / 2;

        if(nums[m] == target)
            return true;

        //Left part is sorted
        if(nums[l] < nums[m])
        {
            if(nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        //Right part is sorted
        else if (nums[l] > nums[m])
        {
            if(nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
        else
            ++ l;
    }

    return false;
}

int main()
{
    std::vector<int> nums{1, 3, 1, 1, 1};

    std::cout<<search(nums, 3)<<std::endl;

    system("pause");
    return 0;
}

