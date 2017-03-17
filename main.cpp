#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

int thirdMax(std::vector<int>& nums)
{
    std::set<int> top3;
    for (auto num : nums)
    {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

int main()
{
    std::vector<int> nums{1,2,3,4};
    std::cout<<thirdMax(nums)<<std::endl;

    system("pause");
    return 0;
}

