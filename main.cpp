#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int maximalSquare(std::vector<std::vector<char> >& matrix)
{
    if(matrix.empty())
        return 0;

    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int> > dp(m, std::vector<int>(n, 0));
    int bian = 0;

    for(int i = 0; i < n; ++ i)
    {
        dp[0][i] = (matrix[0][i] == '0')? 0:1;
        bian = std::max(bian, dp[0][i]);
    }
    for(int i = 0; i < m; ++ i)
    {
        dp[i][0] = (matrix[i][0] == '0')? 0:1;
        bian = std::max(bian, dp[i][0]);
    }

    for(int i = 1; i < m; ++ i)
    {
        for(int j = 1; j < n; ++ j)
        {
            if(matrix[i][j] == '1')
            {
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                bian = std::max(bian, dp[i][j]);
            }
        }
    }

    for(int i = 0; i < m; ++ i)
    {
        for(int j = 0; j < n; ++ j)
            std::cout<<dp[i][j]<<" ";
        std::cout<<std::endl;
    }

    return bian*bian;
}

int main()
{
    std::vector<std::vector<char> > matrix{{'1','1','1'},{'1','1','1'},{'1','1','1'}};
    std::cout<<maximalSquare(matrix)<<std::endl;

    system("pause");
    return 0;
}

