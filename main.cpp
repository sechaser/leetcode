#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

int findPairs(std::vector<int>& nums, int k)
{
    if(nums.size() < 2)
        return 0;

    std::sort(nums.begin(), nums.end());
    int res = 0;

    for(int i = 0; i < nums.size() - 1; ++ i)
    {
        if(i > 0 && nums[i-1] == nums[i])
            continue;

        for(int j = i + 1; j < nums.size(); ++ j)
        {
            if(j > i+1 && nums[j] == nums[j-1])
                continue;
            if(nums[j] - nums[i] == k)
            {
                ++ res;
                break;
            }
        }
    }

    return res;
}

int main()
{
    std::vector<int> nums{1,3,1,5,4};
    std::cout<<findPairs(nums, 0)<<std::endl;

    system("pause");
    return 0;
}

