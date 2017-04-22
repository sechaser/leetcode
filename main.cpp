#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    int sz = nums.size();
    std::vector<int> beginProduct(sz, 0);
    beginProduct[0] = 1;
    std::vector<int> afterProduct(sz, 0);
    afterProduct[sz-1] = 1;

    for(int i = 1; i < sz; ++ i)
        beginProduct[i] = beginProduct[i-1] * nums[i-1];
    for(int i = sz-2; i >= 0; -- i)
        afterProduct[i] = afterProduct[i+1] * nums[i+1];

    std::vector<int> res(sz, 0);
    for(int i = 0; i < sz; ++ i)
        res[i] = beginProduct[i] * afterProduct[i];

    return res;
}

int main()
{
    std::vector<int> nums{1,2,3,4};
    std::vector<int> res = productExceptSelf(nums);

    for(auto &e: res)
        std::cout<<e<<std::endl;

    system("pause");
    return 0;
}

