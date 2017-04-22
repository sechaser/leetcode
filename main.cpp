#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <iterator>

int majorityElement(std::vector<int>& nums)
{
    std::unordered_map<int, int> mp;

    for(int i = 0; i < nums.size(); ++ i)
        ++ mp[nums[i]];

    typedef std::unordered_map<int,int>::iterator iter;
    int accurTimes = -1, majority;
    for(iter it = mp.begin(); it != mp.end(); ++ it)
    {
        if(accurTimes < it->second)
        {
            accurTimes = it->second;
            majority = it->first;
        }
    }

    return majority;
}


int main()
{
    std::vector<int> nums{1, 1, 2, 3};
    std::cout<<majorityElement(nums)<<std::endl;

    system("pause");
    return 0;
}

