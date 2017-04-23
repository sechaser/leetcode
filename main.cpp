#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int numSquares(int n)
{
    if(n <= 0)
        return 0;

    std::vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j*j <= i; ++ j)
            dp[i] = std::min(dp[i], dp[i-j*j]+1);
    }

    return dp[n];
}

int main()
{
    std::cout<<numSquares(12)<<std::endl;

    system("pause");
    return 0;
}

