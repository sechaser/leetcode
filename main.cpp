#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool canJump(std::vector<int>& nums)
{
    int canArrive = 0;

    //canArrive:目前为止能跳到的最远距离
    //i+nums[i]:从当前一步出发能跳到的最远距离
    for(std::vector<int>::size_type i = 0; i <= canArrive && i < nums.size(); ++ i)
    {
        if(i + nums[i] > canArrive)
            canArrive = i + nums[i];
    }

    return canArrive >= nums.size() - 1;
}



int main()
{
    std::vector<int> nums = {3, 2, 1, 0, 4};
    std::cout<<canJump(nums)<<std::endl;

    system("pause");
    return 0;
}

