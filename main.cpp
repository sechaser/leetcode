#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


int jump(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;

    size_t nums_sz = nums.size();
    int step = 0, lastArrive = 0, canArrive = 0;

    /* lastArrive : step can arrive
        canArrive : step + 1 can arrive
     */
    for(int i = 0; i <= canArrive && i < nums_sz; ++ i)
    {
        if(i > lastArrive)
        {
            ++ step;
            lastArrive = canArrive;
        }

        canArrive = std::max(canArrive, i + nums[i]);
    }

    if(canArrive < nums_sz - 1)
        return 0;

    return step;
}


int main()
{
    std::vector<int> nums{3, 2, 1, 0, 4};
    int res = jump(nums);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

