#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    if(nums.empty())
        return std::vector<int>{-1,-1};
    else
    {
        size_t sz = nums.size();
        size_t l = 0, r = sz - 1;
        size_t m = l + (r - l)/2;
        std::vector<int> res;

        while(l <= r)
        {
            if(nums[m] < target)
            {
                l = m + 1;
                m = l + (r - l)/2;
            }
            else if(nums[m] > target)
            {
                if(m == 0)
                    return std::vector<int>{-1,-1};
                r = m - 1;
                m = l + (r - l)/2;
            }
            else
            {
                int i = m;
                while(i != sz && nums[i] == target)
                    ++ i;
                res.push_back(i-1);

                i = m;
                while(i >= 0 && nums[i] == target)
                    -- i;
                res.push_back(i+1);

                break;
            }
        }

        if(res.size() > 1)
            std::sort(res.begin(), res.end());
        else if(res.size() == 1)
            res.push_back(res[0]);
        else
            res = std::vector<int>{-1,-1};

        return res;
    }
}


int main()
{
    std::vector<int> nums{1,3,5};
    int target = 3;

    std::vector<int> res = searchRange(nums, target);
    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

