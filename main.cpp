#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


void solver(std::vector<std::vector<int> >& res, std::vector<int>& tmp, int prev, int n, int k)
{
    if(k == 0)
    {
        res.push_back(tmp);
        return;
    }

    for(int i = prev + 1; i <= n; ++ i)
    {
        tmp.push_back(i);
        solver(res, tmp, i, n, -- k);
        tmp.pop_back();
        ++ k;
    }
}

std::vector<std::vector<int> > combine(int n , int k)
{
    std::vector<std::vector<int> > res;
    std::vector<int> tmp;

    solver(res, tmp, 0, n, k);

    return res;
}



int main()
{
    std::vector<std::vector<int> > res = combine(4, 3);

    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }


    system("pause");
    return 0;
}

