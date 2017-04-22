#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

bool containsNearbyDuplicates(std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); ++ i)
    {
        if(mp.count(nums[i]))
        {
            if(i - mp[nums[i]] <= k)
                return true;
        }
        mp[nums[i]] = i;
    }

    return false;
}

int main()
{
    std::vector<int> nums{1, 2, 1};
    std::cout<<containsNearbyDuplicates(nums, 3)<<std::endl;


    system("pause");
    return 0;
}

