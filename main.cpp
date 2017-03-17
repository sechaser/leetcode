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

std::vector<int> findDuplicates(std::vector<int>& nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); ++ i)
    {
        int index = std::abs(nums[i]) - 1;
        if(nums[index] < 0)
            res.push_back(std::abs(nums[i]));
        else
            nums[index] = -nums[index];
    }

    return res;
}

int main()
{
    std::vector<int> nums{4, 3, 2, 7 ,8, 2, 3 ,1};
    std::vector<int> res = findDuplicates(nums);

    for(int i = 0; i < res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

