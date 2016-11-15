#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int numDecodings(std::string s)
{
    int sz = s.size();
    if(sz == 0)
        return 0;

    std::vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    if(s[0] != '0')
        dp[1] = 1;
    else
        dp[1] = 0;

    for(int i = 2; i <= sz; ++ i)
    {
        if(s[i-1] != '0')
            dp[i] = dp[i-1];
        else
            dp[i] = 0;

        if(s[i-2] == '1' || (s[i-2] == '2' && (s[i-1] <= '6')))
            dp[i] += dp[i-2];
    }

    return dp[sz];
}

int main()
{
    std::string s = "17";
    std::cout<<numDecodings(s)<<std::endl;

    system("pause");
    return 0;
}

