#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <string.h>

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if(s1.size() == 0)
        return s2 == s3;
    if(s2.size() == 0)
        return s1 == s3;

    bool dp[s1.size() + 1][s2.size() + 1];
    memset(dp, 0, sizeof(dp));

    if(s3.size() != 0)
    {
        if(s1[0] == s3[0])
            dp[1][0] = 1;
        else
            dp[1][0] = 0;

        if(s2[0] == s3[0])
            dp[0][1] = 1;
        else
            dp[0][1] = 0;
    }
    else
        return false;

    if(s1.size() + s2.size() != s3.size())
        return false;


    for(int i = 0; i <= s1.size(); ++ i)
    {
        for(int j = 0; j <= s2.size(); ++ j)
        {
            if(j > 0)
            {
                if(dp[i][j-1] && s3[i+j-1] == s2[j-1])
                    dp[i][j] = 1;
            }
            if(i > 0)
            {
                if(dp[i-1][j] && s3[i+j-1] == s1[i-1])
                    dp[i][j] = 1;
            }
        }
    }

    return dp[s1.size()][s2.size()];
}


int main()
{
    std::string s1 = "ca", s2 = "db", s3 = "cdba";
    std::cout<<isInterleave(s1, s2, s3)<<std::endl;


    system("pause");
    return 0;
}

