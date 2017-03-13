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

//    std::unordered_map<int, std::vector<std::pair<int, int> >  > pairs;
//    pairs.reserve(sz * sz);
//    std::sort(nums.begin(), nums.end());

//    for(std::vector<int>::size_type i = 0; i != sz; ++ i)
//    {
//        for(std::vector<int>::size_type j = i+1; j != sz; ++ j)
//            pairs[nums[i]+nums[j]].push_back(std::make_pair(i,j));
//    }

//    for(std::vector<int>::size_type i = 0; i != sz-3; ++ i)
//    {
//        if(i > 0 && nums[i] == nums[i-1])
//            continue;
//        for(std::vector<int>::size_type j = i+1; j != sz-2; ++ j)
//        {
//            if(j > i+1 && nums[j] == nums[j-1])
//                continue;

//            if(pairs.find(target-nums[i]-nums[j]) != pairs.end())
//            {
//                std::vector<std::pair<int, int> > twoSum = pairs[target-nums[i]-nums[j]];
//                bool numberone = 1;

//                for(std::vector<std::pair<int, int> >::size_type k = 0; k != twoSum.size(); ++ k)
//                {
//                    if(twoSum[k].first <= j)
//                        continue;

//                    if(numberone || (res.back()[2] != nums[twoSum[k].first]))
//                    {
//                        res.push_back(std::vector<int>{nums[i], nums[j], nums[twoSum[k].first], nums[twoSum[k].second]});
//                        numberone = 0;
//                    }
//                }
//            }
//        }
//    }

//    return res;
//}


//std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
//{
//    std::vector<std::vector<int> > res;
//    if(nums.size() < 4)
//        return res;

//    std::sort(nums.begin(), nums.end());
//    for(std::vector<int>::size_type i = 0; i < nums.size() - 3; ++ i)
//    {
//        if(i > 0 && nums[i] == nums[i - 1])
//            continue;
//        int target3 = target - nums[i];

//        for(std::vector<int>::size_type j = i + 1; j < nums.size() - 2; ++ j)
//        {
//            if(j > i + 1 && nums[j] == nums[j-1])
//                continue;
//            int target2 = target3 - nums[j];
//            int l = j + 1, r = nums.size() - 1;

//            while(l < r)
//            {
//                if(nums[l] + nums[r] == target2)
//                {
//                    res.push_back(std::vector<int>{nums[i], nums[j], nums[l], nums[r]});
//                    ++ l;
//                    -- r;
//                    while(l < r && nums[l] == nums[l-1])
//                       ++ l;
//                    while(l < r && nums[r] == nums[r+1])
//                       -- r;
//                }
//                else if(nums[l] + nums[r] < target2)
//                    ++ l;
//                else
//                    -- r;
//            }
//        }
//    }

//    return res;
//}
void twoSum(std::vector<int>& nums, int beg, int end, int target, std::vector<int>& tmp,
            std::vector<std::vector<int> >& res)
{
    while(beg < end)
    {
        if(nums[beg] + nums[end] == target)
        {
            tmp.push_back(nums[beg]);
            tmp.push_back(nums[end]);
            res.push_back(tmp);
            tmp.pop_back();
            tmp.pop_back();
            ++ beg;
            -- end;

            while(beg < end && nums[beg] == nums[beg-1])
                ++ beg;
            while(beg < end && nums[end] == nums[end+1])
                -- end;
        }
        else if(nums[beg] + nums[end] < target)
            ++ beg;
        else
            -- end;
    }
}

void kSum(std::vector<int>& nums, int beg, int end, int target, int k, std::vector<int>& tmp,
          std::vector<std::vector<int> >& res)
{
    if(k == 1)
    {
        for(int i = beg; i <= end; ++ i)
        {
            if(nums[i] == target)
            {
                tmp.push_back(nums[i]);
                res.push_back(tmp);
                tmp.pop_back();
                return;
            }
        }
        return;  /* May not found the target, return too*/
    }

    /* Time will exceed if not add this*/
//    if(k == 2)
//    {
//        twoSum(nums, beg, end, target, tmp, res);
//        return;
//    }

    for(int i = beg; i <= end-k+1; ++ i)
    {
        if(i > beg && nums[i] == nums[i-1])
            continue;
        tmp.push_back(nums[i]);
        kSum(nums, i+1, end, target-nums[i], k-1, tmp, res);
        tmp.pop_back();
    }

}

std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int> > res;
    std::vector<int> tmp;

    if(nums.size() < 4)
        return res;
    std::sort(nums.begin(), nums.end());

    kSum(nums, 0, nums.size() - 1, target, 4, tmp, res);

    return res;
}

int main()
{
    std::vector<int> s{1, -1, -2, 2, 0};
    int target = 0;

    std::vector<std::vector<int> > res = fourSum(s, target);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<res[i][j]<<" ";
        std::cout<<std::endl;
    }

    return 0;
}

