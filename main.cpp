#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


void solver(std::vector<int>& nums, std::vector<std::vector<int> >& res, std::vector<int>& tmp, int idx, int sz)
{
    if(sz == 0)
    {
        res.push_back(tmp);
        return;
    }

    for(int i = idx; i != nums.size(); ++ i)
    {
        tmp.push_back(nums[i]);
        solver(nums, res, tmp, i+1, --sz);
        tmp.pop_back();
        ++ sz;
    }
}

std::vector<std::vector<int> > subsets(std::vector<int>& nums)
{
    std::vector<std::vector<int> > res;

    for(std::vector<int>::size_type num = 0; num <= nums.size(); ++ num)
    {
        std::vector<int> tmp;
        solver(nums, res, tmp, 0, num);
    }

    return res;
}


int main()
{
    std::vector<int> nums{1,2,3,4};
    std::vector<std::vector<int> > res = subsets(nums);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

