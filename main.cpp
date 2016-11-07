#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <math.h>

int minDistance(std::string word1, std::string word2)
{
    int sz1 = word1.size(), sz2 = word2.size();
    int dp[sz1+1][sz2+1];

    for(int i = 0; i <= sz1; ++ i)
        dp[i][0] = i;
    for(int i = 0; i <= sz2; ++ i)
        dp[0][i] = i;

    for(int i = 1; i <= sz1; ++ i)
    {
        for(int j = 1; j <= sz2; ++ j)
        {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }

    return dp[sz1][sz2];
}

int main()
{
    std::string word1 = "a", word2 = "b";
    std::cout<<minDistance(word1, word2)<<std::endl;


    system("pause");
    return 0;
}

