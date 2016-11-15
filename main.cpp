#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void solver(std::vector<int>& nums, std::vector<std::vector<int> >& res, std::vector<int>& tmp, int beg, int len)
{
    if(len == 0)
    {
        res.push_back(tmp);
        return;
    }

    for(int i = beg; i != nums.size(); ++ i)
    {
        if(i > beg && nums[i] == nums[i - 1])
            continue;

        tmp.push_back(nums[i]);
        solver(nums, res, tmp, i + 1, -- len);
        tmp.pop_back();
        ++ len;
    }
}

std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums)
{
    std::vector<std::vector<int> > res;
    std::sort(nums.begin(), nums.end());

    //The length of subset in range [0, nums.size()]
    for(std::vector<int>::size_type len = 0; len <= nums.size(); ++ len)
    {
        std::vector<int> tmp;
        solver(nums, res, tmp, 0, len);
    }

    return res;
}


int main()
{
    std::vector<int> nums{1, 2, 2};
    std::vector<std::vector<int> > res = subsetsWithDup(nums);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

