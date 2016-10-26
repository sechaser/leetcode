#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void mysolver(std::vector<int>& candidates, int beg, int target, std::vector<int>& tmp, std::vector<std::vector<int> >& res)
{
    if(target == 0)
    {
        res.push_back(tmp);
        return;
    }

    for(int i = beg; i != candidates.size() && candidates[i] <= target; ++ i)
    {
        if(i > beg && candidates[i] == candidates[i - 1])
            continue;

        tmp.push_back(candidates[i]);
        mysolver(candidates, i + 1, target - candidates[i], tmp, res);
        tmp.pop_back();
    }
}

std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target)
{
    std::vector<std::vector<int> > res;
    if(candidates.size() < 1)
        return res;

    std::sort(candidates.begin(), candidates.end());
    std::vector<int> tmp;
    mysolver(candidates, 0, target, tmp, res);

    return res;
}


int main()
{
    std::vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    std::vector<std::vector<int> > res = combinationSum2(candidates, 8);

    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

