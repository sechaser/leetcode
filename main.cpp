#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    if(k == 2)
    {
        twoSum(nums, beg, end, target, tmp, res);
        return;
    }

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

