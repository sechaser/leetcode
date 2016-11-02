#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//*****************************************Time:O(n^3)*************************************
//int maxSubArray(std::vector<int>& nums)
//{
//    int res = INT_MIN;

//    size_t nums_sz = nums.size();

//    //Consider every element in nums vector
//    for(std::vector<int>::size_type i = 0; i != nums_sz; ++ i)
//    {
//        //Consider different section of element nums[i]
//        for(std::vector<int>::size_type j = i; j != nums_sz; ++ j)
//        {
//            int sum = 0;
//            //Consider section [i, j], calculate its sum
//            for(std::vector<int>::size_type k = i; k <= j; ++ k)
//                sum += nums[k];

//            if(sum > res)
//                res = sum;
//        }
//    }

//    return res;
//}



//***************************************Time:O(n^2)********************************************
//int maxSubArray(std::vector<int>& nums)
//{
//    int res = INT_MIN;
//    size_t nums_sz = nums.size();

//    for(std::vector<int>::size_type i = 0; i != nums_sz; ++ i)
//    {
//        int sum = 0;
//        for(std::vector<int>::size_type j = i; j != nums_sz; ++ j)
//        {
//            sum += nums[j];
//            if(sum > res)
//                res = sum;
//        }
//    }

//    return res;
//}

//***************************************Time:O(n)***********************************************
int maxSubArray(std::vector<int>& nums)
{
    int res = INT_MIN, sum = -1;
    size_t nums_sz = nums.size();

    for(int i = 0; i != nums_sz; ++ i)
    {
        if(sum > 0)
            sum += nums[i];
        else
            sum = nums[i];

        if(sum > res)
            res = sum;
    }

    return res;
}



int main()
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<maxSubArray(nums)<<std::endl;

    system("pause");
    return 0;
}

