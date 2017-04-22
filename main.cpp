#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void solver(int k, int n, int beg, int end, std::vector<int>& tmp,
            std::vector<std::vector<int> >& res)
{
    if(k == 0 && n == 0)
    {
        res.push_back(tmp);
        return;
    }

    if(k == 0 || n == 0)
        return;

    for(int i = beg; i <= end; ++ i)
    {
        tmp.push_back(i);
        solver(k-1, n-i, i+1, end, tmp, res);
        tmp.pop_back();
    }
}

std::vector<std::vector<int> > combinationSum3(int k, int n)
{
    std::vector<int> tmp;
    std::vector<std::vector<int> > res;

    solver(k, n, 1, 9, tmp, res);
    return res;
}

int main()
{
    std::vector<std::vector<int> > res = combinationSum3(3, 9);
    for(int i = 0; i < res.size(); ++ i)
    {
        for(int j = 0; j < res[i].size(); ++ j)
            std::cout<<res[i][j]<<" ";
        std::cout<<std::endl;
    }


    system("pause");
    return 0;
}

