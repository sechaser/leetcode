#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int minimumTotal(std::vector<std::vector<int> >& triangle)
{
    if(triangle.empty())
        return 0;

    std::vector<int>::size_type sz = triangle.size();
    std::vector<int> dp(sz, 0);

    for(int i = 0; i != sz; ++ i)
        dp[i] = triangle[sz-1][i];

    for(int i = sz - 2; i >= 0; -- i)
    {
        for(int j = 0; j <= i; ++ j)
            dp[j] = triangle[i][j] + std::min(dp[j], dp[j+1]);
    }

    return dp[0];
}


int main()
{
    std::vector<std::vector<int> > triangle{{1}, {2, 1}, {3,2,1}, {4,3,2,1}};
    std::cout<<minimumTotal(triangle)<<std::endl;

    system("pause");
    return 0;
}

