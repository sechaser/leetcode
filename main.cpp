#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void mysolver(std::vector<int>& candiates, int beg, int target, std::vector<int>& tmp, std::vector<std::vector<int> >& res)
{
    if(target == 0)
    {
        res.push_back(tmp);
        return;
    }

    for(int i = beg; i != candiates.size() && candiates[i] <= target; ++ i)
    {
        if(i == 0 || candiates[i] != candiates[i-1])
        {
            tmp.push_back(candiates[i]);
            mysolver(candiates, i, target - candiates[i], tmp, res);
            tmp.pop_back();
        }
    }
}

std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target)
{
    std::vector<std::vector<int> > res;
    if(candidates.empty())
        return res;

    std::sort(candidates.begin(), candidates.end());
    std::vector<int> tmp;
    mysolver(candidates, 0, target, tmp, res);

    return res;
}

int main()
{
    std::vector<int> candiates{8, 7, 4, 3};
    int target = 11;

    std::vector<std::vector<int> > res = combinationSum(candiates, target);

    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

