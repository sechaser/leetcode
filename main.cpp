#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

//space:O(n)
//int singleNumber(std::vector<int>& nums)
//{
//    std::unordered_set<int> ht;

//    for(std::vector<int>::size_type t = 0; t != nums.size(); ++ t)
//    {
//        if(ht.count(nums[t]))
//            ht.erase(nums[t]);
//        else
//            ht.insert(nums[t]);
//    }

//    return *ht.begin();
//}

//No extra memory
int singleNumber(std::vector<int>& nums)
{
    for(int i = 1; i < nums.size(); ++ i)
        nums[0] ^= nums[i];

    return nums[0];
}

int main()
{
    std::vector<int> nums{1, 1, 2, 3, 2, 5, 3};
    std::cout<<singleNumber(nums)<<std::endl;

    system("pause");
    return 0;
}

