#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

int findMaxConsecutiveOnes(std::vector<int>& nums)
{
    int max1s = 0;
    int cur1s = 0;

    int i = 0;
    while(i < nums.size())
    {
        while(i < nums.size() && nums[i] != 1)
            ++ i;

        while(i < nums.size() && nums[i] == 1)
        {
            ++ cur1s;
            ++ i;
        }

        if(cur1s > max1s)
            max1s = cur1s;
        cur1s = 0;
    }

    return max1s;
}

int main()
{
    std::vector<int> nums{0, 0, 0, 0};
    std::cout<<findMaxConsecutiveOnes(nums)<<std::endl;

    system("pause");
    return 0;
}

