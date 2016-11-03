#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


int uniquePathsWithObstacles(std::vector<std::vector<int> >& obstacleGrid)
{
    if(obstacleGrid.empty())
        return 0;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<int> dp(n, 0);
    dp[0] = 1;

    for(int i = 0; i != m; ++ i)
    {
        for(int j = 0; j != n; ++ j)
        {
            if(obstacleGrid[i][j] == 1)
                dp[j] = 0;
            else
            {
                if(j > 0)
                    dp[j] = dp[j] + dp[j-1];
            }
        }
    }

    return dp[n-1];
}

int main()
{
    std::vector<std::vector<int> > obstacleGrid{std::vector<int>{0,0,0}, std::vector<int>{0,1,0}, std::vector<int>{0,0,0}};
    std::cout<<uniquePathsWithObstacles(obstacleGrid)<<std::endl;

    system("pause");
    return 0;
}

