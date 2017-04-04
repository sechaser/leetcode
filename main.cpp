#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


int search(std::vector<int>& nums, int target)
{
    if(nums.empty())
        return -1;
    else
    {
        size_t sz = nums.size();
        size_t l = 0, r = sz - 1;

        while(l <= r)
        {
            size_t m = l + (r - l)/2;

            if(nums[m] == target)
                return m;

            if(nums[l] < nums[m])    //left part is sorted
            {
                if(nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if(nums[l] > nums[m])
            {
                if(nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            /* may be : l == m*/
            else
                ++ l;
        }

        return -1;
    }
}

int main()
{
    std::vector<int> nums{1};
    int res = search(nums, 2);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

