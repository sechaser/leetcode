#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <iterator>

std::vector<int> majorityElement(std::vector<int>& nums)
{
    std::unordered_map<int, int> mp;
    int sz = nums.size();
    for(int i = 0; i < sz; ++ i)
        ++ mp[nums[i]];

    typedef std::unordered_map<int,int>::iterator iter;
    std::vector<int> res;

    for(iter it = mp.begin(); it != mp.end(); ++ it)
    {
        if(it->second > (sz/3))
            res.push_back(it->first);
    }

    return res;
}

int main()
{
    std::vector<int> nums{1,1,1,1,2,2,2,2,9};
    std::vector<int> res = majorityElement(nums);

    for(auto &e:res)
        std::cout<<e<<" ";
    std::cout<<std::endl;

    system("pause");
    return 0;
}

