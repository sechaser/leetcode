#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void nextPermutation(std::vector<int>& nums)
{
    if(nums.size() < 2)
        return;

    int i = nums.size() - 2;
    while(i >= 0 && nums[i] >= nums[i+1])
        -- i;

    if(i < 0)
    {
        std::sort(nums.begin(), nums.end());
        return;
    }

    int j = i + 1;
    while(j < nums.size() && nums[j] > nums[i])
        ++ j;
    -- j;

    std::swap(nums[i], nums[j]);
    std::sort(nums.begin() + i + 1, nums.end());
}


int main()
{
    std::vector<int> nums{3, 2, 1};
    nextPermutation(nums);

    for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
        std::cout<<nums[i]<<std::endl;

    system("pause");
    return 0;
}

