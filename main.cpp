#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int maxProduct(std::vector<int>& nums)
{
    int global = nums[0];
    int max_local = nums[0], min_local = nums[0];

    for(int i = 1; i < nums.size(); ++ i)
    {
        int tmp = max_local;
        max_local = std::max(std::max(max_local*nums[i], nums[i]), min_local*nums[i]);
        min_local = std::min(std::min(min_local*nums[i], nums[i]), tmp*nums[i]);
        global = std::max(max_local, global);
    }

    return global;
}

int main()
{
    std::vector<int> nums{-2, 3, -4};
    std::cout<<maxProduct(nums)<<std::endl;

    system("pause");
    return 0;
}

