#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isScramble(std::string s1, std::string s2)
{
    if(s1.size() != s2.size())
        return false;
    if(s1.empty())
        return true;

    std::vector<std::vector<std::vector<bool> > > dp(s1.size(), std::vector<std::vector<bool> >(s2.size(), std::vector<bool>(s1.size()+1, 0)));
    for(int i = 0; i != s1.size(); ++ i)
    {
        for(int j = 0; j != s2.size(); ++ j)
        {
            if(s1[i] == s2[j])
                dp[i][j][1] = 1;
            else
                dp[i][j][1] = 0;
        }
    }

    for(int len = 2; len <= s1.size(); ++ len)
    {
        for(int i = 0; i != s1.size()-len+1; ++ i)
        {
            for(int j = 0; j != s2.size()-len+1; ++ j)
            {
                for(int k = 1; k != len; ++ k)
                {
                    if((dp[i][j][k]&&dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k]&&(dp[i+k][j][len-k])))
                    {
                        dp[i][j][len] = 1;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][0][s1.size()];
}

int main()
{
    std::string s1 = "great", s2 = "rgeat";
    std::cout<<isScramble(s1, s2)<<std::endl;

    system("pause");
    return 0;
}

