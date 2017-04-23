#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//int findDuplicate(std::vector<int>& nums)
//{
//    for(int i = 0; i < nums.size(); ++ i)
//    {
//        int index = std::abs(nums[i]);

//        if(nums[index - 1] < 0)
//            return index;
//        else
//            nums[index-1] = -nums[index-1];
//    }
//}

//int findDuplicate(std::vector<int>& nums)
//{
//    int slow = nums[0];
//    int fast = nums[nums[0]];

//    while(slow != fast)
//    {
//        slow = nums[slow];
//        fast = nums[nums[fast]];
//    }

//    fast = 0;
//    while(slow != fast)
//    {
//        fast = nums[fast];
//        slow = nums[slow];
//    }

//    return slow;
//}



int main()
{
    std::vector<int> nums{1,2,3,3};
    std::cout<<findDuplicate(nums)<<std::endl;

    system("pause");
    return 0;
}

