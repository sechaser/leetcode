#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{
    std::vector<bool> dp(s.size(), 0);
    dp[0] = 1;

    for(std::string::size_type i = 0; i != s.size(); ++ i)
    {
        for(int j = i; j >= 0; -- j)
        {
            if(dp[j] && (std::find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end()))
            {
                dp[i+1] = 1;
                break;
            }
        }
    }

    return dp[s.size()];
}


int main()
{
    std::vector<std::string> wordDict = {"leet", "code"};
    std::string s = "leetcode";

    std::cout<<wordBreak(s, wordDict)<<std::endl;

    system("pause");
    return 0;
}

