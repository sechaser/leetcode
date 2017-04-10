#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int minPathSum(std::vector<std::vector<int> >& grid)
{
    if(grid.empty())
        return 0;

    int m = grid.size(), n = grid[0].size();
    std::vector<int> dp(n, 0);

    for(int i = 0; i < n; ++ i)
        dp[i] = (i > 0)? dp[i-1]+grid[0][i] : grid[0][i];

    for(int i = 1; i < m; ++ i)
    {
        for(int j = 0; j < n; ++ j)
            dp[j] = (j > 0) ? std::min(dp[j-1] + grid[i][j], dp[j] + grid[i][j]) : dp[j] + grid[i][j];
    }

    return dp[n-1];
}

int main()
{
    std::vector<std::vector<int> > grid{std::vector<int>{1,4,3}, std::vector<int>{3,1,1}, std::vector<int>{5,100,1}};
    std::cout<<minPathSum(grid)<<std::endl;

    system("pause");
    return 0;
}

