#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

//Time limit exceed
//int threeSumClosest(std::vector<int>& nums, int target)
//{
//    std::vector<int>::size_type sz = nums.size();
//    std::sort(nums.begin(), nums.end());
//    int mingap = INT_MAX;
//    int res;

//    int target2;
//    for(std::vector<int>::size_type i = 0; i != sz - 2; ++ i)
//    {
//        if(i > 0 && nums[i] == nums[i-1])
//            continue;

//        target2 = target - nums[i];
//        std::vector<int>::size_type j, k;

//        for(j = i + 1; j != sz - 1; ++ j)
//        {
//            for(k = j + 1; k != sz; ++ k)
//            {
//                if(std::abs(nums[j] + nums[k] - target2) < mingap)
//                {
//                    mingap = std::abs(nums[j] + nums[k] - target2);
//                    res = nums[i] + nums[j] + nums[k];
//                }
//            }
//        }
//    }

//    return res;
//}

//
//int threeSumClosest(std::vector<int>& nums, int target)
//{
//    std::vector<int>::size_type sz = nums.size();
//    sort(nums.begin(), nums.end());

//    int res, mingap = INT_MAX;
//    int twoSum;
//    std::vector<int>::size_type head, tail;
//    for(std::vector<int>::size_type i = 0; i != sz-2; ++ i)
//    {
//        int target2 = target - nums[i];

//        head = i + 1;
//        tail = sz - 1;
//        int roundgap = INT_MAX;
//        int tmpres;

//        while(head < tail)
//        {
//            twoSum = nums[head] + nums[tail];
//            if(twoSum < target2)
//            {
//                if(target2 - twoSum < roundgap)
//                {
//                    roundgap = target2 - twoSum;
//                    tmpres   = twoSum;
//                }
//                ++ head;
//            }
//            else if(twoSum > target2)
//            {
//                if(twoSum - target2 < roundgap)
//                {
//                    roundgap = twoSum - target2;
//                    tmpres   = twoSum;
//                }
//                -- tail;
//            }
//            else
//                return target;
//        }

//        if(std::abs(tmpres + nums[i] - target) < mingap)
//        {
//            mingap = abs(tmpres + nums[i] - target);
//            res    = tmpres + nums[i];
//            if(res == target)
//                return res;
//        }
//    }

//    return res;
//}

int threeSumClosest(std::vector<int>& nums, int target)
{
    if(nums.size() < 3)
        return INT_MAX;

    int minDiff = INT_MAX;
    int l, r;
    std::sort(nums.begin(), nums.end());

    for(std::vector<int>::size_type i = 0; i != nums.size() - 2; ++ i)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        l = i + 1, r = nums.size() - 1;
        while(l < r)
        {
            int curDiff = target - (nums[i] + nums[l] + nums[r]);

            if(std::abs(curDiff) < std::abs(minDiff))
                minDiff = curDiff;

            if(curDiff == 0)
                break;
            else if(curDiff > 0)
                ++ l;
            else
                -- r;
        }
    }

    return target - minDiff;
}

int main()
{
    std::vector<int> iv{0, 0, 0};
    int target = 1;

    int res = threeSumClosest(iv, target);
    std::cout<<res<<std::endl;

    return 0;
}

