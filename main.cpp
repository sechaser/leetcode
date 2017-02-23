#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//int firstMissiongPositive(std::vector<int>& nums)
//{
//    if(nums.empty())
//        return 1;

//    std::sort(nums.begin(), nums.end());
//    size_t i = 0;

//    while(i != nums.size())
//    {
//        if(nums[i] < 0)
//            ++ i;
//        else
//            break;
//    }

//    if(nums[i] <= 1)
//    {
//        size_t j = i + 1;
//        while(j != nums.size())
//        {
//            if((nums[j] == nums[j-1] + 1 ) || (nums[j] == nums[j - 1]))
//            {
//                ++ j;
//                continue;
//            }
//            else
//                break;
//        }

//        return nums[j-1]+1;
//    }
//    else
//        return 1;
//}



int firstMissiongPositive(std::vector<int>& A)
{
    int i=0;
    int n = A.size();

    while(i<n)
    {
        if(A[i]!=i+1 && A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
            std::swap(A[i],A[A[i]-1]);
        else
            i++;
    }
    for(int i=0; i<n; i++) {
        if(A[i]!=i+1) return i+1;
    }

    return n+1;
}


int main()
{
    std::vector<int> nums = {-2, 5, 3, -7, 1, 6, -8};
    int res = firstMissiongPositive(nums);

    for(int i = 0; i != nums.size(); ++ i)
        std::cout<<nums[i]<<" ";
    std::cout<<std::endl;

    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

