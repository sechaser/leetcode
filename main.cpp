#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void swap(std::vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


bool canSwap(std::vector<int>& nums, int i, int j)
{
    for(int k = i; k != j; ++ k)
    {
        if(nums[k] == nums[j])
            return false;
    }

    return true;
}


void allRange(std::vector<int>& nums, std::vector<std::vector<int> >& res, int beg, int end)
{
    if(beg == end)
        res.push_back(nums);
    else
    {
        for(int i = beg; i != end; ++ i)
        {
            if(canSwap(nums, beg, i))
            {
                swap(nums, beg, i);
                allRange(nums, res, beg+1, end);
                swap(nums, beg, i);
            }
        }
    }
}


std::vector<std::vector<int> > permute(std::vector<int>& nums)
{
    std::vector<std::vector<int> > res;
    if(nums.empty())
        return res;

    size_t nums_sz = nums.size();
    allRange(nums, res, 0, nums_sz);

    return res;
}


int main()
{
    std::vector<int> nums{1,2,2};
    std::vector<std::vector<int> > res = permute(nums);

    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }
    system("pause");
    return 0;
}

