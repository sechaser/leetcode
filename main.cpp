#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <iterator>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

//std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
//{
//    std::vector<int> res;
//    std::map<int, int> mp;

//    for(int i = 0; i < nums.size(); ++ i)
//        mp[i+1] = 0;

//    for(int i = 0; i < nums.size(); ++ i)
//        ++ mp[nums[i]];

//    for(std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++ it)
//    {
//        if(it->second == 0)
//            res.push_back(it->first);
//    }

//    return res;
//}


std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); ++ i)
    {
        int index = std::abs(nums[i]) - 1;
        if(nums[index] > 0)
            nums[index] = -nums[index];
    }

    for(int i = 0; i < nums.size(); ++ i)
    {
        if(nums[i] > 0)
            res.push_back(i+1);
    }

    return res;
}

int main()
{
    std::vector<int> nums{4,3,2,7,8,2,3,1};
    std::vector<int> res = findDisappearedNumbers(nums);
    for(int i = 0; i < res.size(); ++ i)
        std::cout<<res[i]<<" ";


    system("pause");
    return 0;
}

