#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

int longsetConsecutive(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;

    std::unordered_set<int> ht;
    for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
        ht.insert(nums[i]);

    int maxLen = 1;
    for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
    {
//        if(ht.empty())
//            break;

        int curNum = nums[i];
        int curLen = 0;

        while(ht.count(curNum))
        {
            ++ curLen;
            ht.erase(curNum);
            ++ curNum;
        }

        curNum = nums[i] - 1;
        while(ht.count(curNum))
        {
            ++ curLen;
            ht.erase(curNum);
            -- curNum;
        }

        maxLen = std::max(maxLen, curLen);
    }

    return maxLen;
}


int main()
{
    std::vector<int> nums{100, 4, 200, 1, 3, 2};
    std::cout<<longsetConsecutive(nums)<<std::endl;

    system("pause");
    return 0;
}

