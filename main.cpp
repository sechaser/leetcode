#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void moveZeroes(std::vector<int>& nums)
{
    int j = 0;
    int sz = nums.size();

    for(int i = 0; i < sz; ++ i)
    {
        if(nums[i] != 0)
        {
            nums[j] = nums[i];
            ++ j;
        }
    }

    for(int i = j; i < sz; ++ i)
        nums[i] = 0;

    for(int i = 0; i < sz; ++ i)
        std::cout<<nums[i]<<" ";
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> nums{0,1,0,3,12};
    moveZeroes(nums);

    system("pause");
    return 0;
}

