#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target)
//{
//    size_t sz = nums.size();
//    std::sort(nums.begin(), nums.end());
//    std::vector<std::vector<int> > res;

//    if(sz < 4)
//        return res;

//    int target2;
//    int head, tail, temp;
//    for(std::vector<int>::size_type first = 0; first != sz-3; ++ first)
//    {
//        if(first > 0 && nums[first] == nums[first-1])
//            continue;

//        for(std::vector<int>::size_type second = first+1; second != sz-2; ++ second)
//        {
//            if(second > first+1 && nums[second] == nums[second-1])
//                continue;

//            target2 = target - (nums[first] + nums[second]);
//            head = second + 1;
//            tail = sz - 1;

//            while(head < tail)
//            {
//                temp = nums[head] + nums[tail];
//                if(temp < target2)
//                    ++ head;
//                else if(temp > target2)
//                    -- tail;
//                else
//                {
//                    std::vector<int> oneres{nums[first], nums[second], nums[head], nums[tail]};
//                    res.push_back(oneres);

//                    int k = head + 1;
//                    while(k < tail && nums[k] == nums[head])
//                        ++ k;
//                    head = k;

//                    k = tail - 1;
//                    while(head < k && nums[k] == nums[tail])
//                        -- k;
//                    tail = k ;
//                }
//            }
//        }
//    }

//    return res;
//}

std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target)
{
    size_t sz = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int> > res;

    if(sz < 4)
        return res;

    std::unordered_map<int, std::vector<std::pair<int, int> >  > pairs;
    pairs.reserve(sz * sz);
    std::sort(nums.begin(), nums.end());

    for(std::vector<int>::size_type i = 0; i != sz; ++ i)
    {
        for(std::vector<int>::size_type j = i+1; j != sz; ++ j)
            pairs[nums[i]+nums[j]].push_back(std::make_pair(i,j));
    }

    for(std::vector<int>::size_type i = 0; i != sz-3; ++ i)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        for(std::vector<int>::size_type j = i+1; j != sz-2; ++ j)
        {
            if(j > i+1 && nums[j] == nums[j-1])
                continue;

            if(pairs.find(target-nums[i]-nums[j]) != pairs.end())
            {
                std::vector<std::pair<int, int> > twoSum = pairs[target-nums[i]-nums[j]];
                bool numberone = 1;

                for(std::vector<std::pair<int, int> >::size_type k = 0; k != twoSum.size(); ++ k)
                {
                    if(twoSum[k].first <= j)
                        continue;

                    if(numberone || (res.back()[2] != nums[twoSum[k].first]))
                    {
                        res.push_back(std::vector<int>{nums[i], nums[j], nums[twoSum[k].first], nums[twoSum[k].second]});
                        numberone = 0;
                    }
                }
            }
        }
    }

    return res;
}

int main()
{
    std::vector<int> s{-1,0,1,2,-1,-4};
    int target = (-1);

    std::vector<std::vector<int> > res = fourSum(s, target);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<res[i][j]<<" ";
        std::cout<<std::endl;
    }

    return 0;
}

