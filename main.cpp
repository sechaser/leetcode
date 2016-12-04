#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <string.h>

int numDistinct(std::string s, std::string t)
{
    int lens = s.size(), lent = t.size();
    if(lent == 0)
        return 1;
    else if(lens == 0)
        return 0;

    int dp[lens+1][lent+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= lens; ++ i)
        dp[i][0] = 1;

    for(int i = 1; i <= lens; ++ i)
    {
        for(int j = 1; j <= lent; ++ j)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[lens][lent];
}


int main()
{
    std::string s = "rabbbit", t = "rabbit";
    std::cout<<numDistinct(s, t)<<std::endl;

    system("pause");
    return 0;
}

