#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int findMin(std::vector<int>& nums)
{
    int left = 0, right = nums.size() -1;

    while(left < right)
    {
        if(nums[left] < nums[right])
            return nums[left];

        int mid = (left + right) / 2;

        if(nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left];
}


int main()
{
    std::vector<int> nums{1};
    std::cout<<findMin(nums)<<std::endl;


    system("pause");
    return 0;
}

