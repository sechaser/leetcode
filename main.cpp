#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


//int jump(std::vector<int>& nums)
//{
//    if(nums.empty())
//        return 0;

//    size_t nums_sz = nums.size();
//    int step = 0, prevStepDis = 0, currStepDis = 0;
//    for(int i = 0; i != nums_sz; ++ i)
//    {
//        //If the current index exceed the farest distance with only "step", we should add a step and go far.
//        if(i > prevStepDis)
//        {
//            prevStepDis = currStepDis;
//            ++ step;
//        }

//        //Record the farest distance we can reach with "step+1".
//        currStepDis = std::max(currStepDis, i + nums[i]);
//    }


//    return step;
//}




//This solution has considered that we can not reach the last index.
int jump(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;

    size_t nums_sz = nums.size();
    int step = 0, lastArrive = 0, canArrive = 0;

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

