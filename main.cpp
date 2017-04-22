#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int findPeakElement(std::vector<int>& nums)
{
    if(nums.size() == 1 || nums[0] > nums[1])
        return 0;

    int sz = nums.size();
    if(nums[sz-1] > nums[sz-2])
        return sz-1;

    for(int i = 1; i < sz-1; ++ i)
    {
        if((nums[i] > nums[i-1]) && (nums[i] > nums[i+1]))
            return i;
    }
}

int main()
{
    std::vector<int> nums{1,2,4,3};
    std::cout<<findPeakElement(nums)<<std::endl;

    system("pause");
    return 0;
}

