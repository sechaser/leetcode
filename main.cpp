#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void solver(std::string& s, int pos, std::vector<std::vector<bool> >& dp,
            std::vector<std::string>& tmp, std::vector<std::vector<std::string> >& res)
{
    if(pos == s.size())
    {
        res.push_back(tmp);
        return;
    }

    for(int i = pos; i != s.size(); ++ i)
    {
        if(dp[pos][i])
        {
            int len = i - pos + 1;
            tmp.push_back(s.substr(pos, len));
            solver(s, i+1, dp, tmp, res);
            tmp.pop_back();
        }
    }
}

std::vector<std::vector<std::string> > parition(std::string s)
{
    std::vector<std::vector<std::string> > res;
    if(s.size() == 0)
        return res;

    int sz = s.size();
    std::vector<std::vector<bool> > dp(sz, std::vector<bool>(sz, 0));

    for(int i = sz-1; i >= 0; -- i)
    {
        for(int j = i; j != sz; ++ j)
        {
            if((s[i] == s[j]) && ((j-i<=2) || dp[i+1][j-1]))
                dp[i][j] = true;
        }
    }

    std::vector<std::string> tmp;
    solver(s, 0, dp, tmp, res);

    return res;
}


int main()
{
    std::string s = "aab";
    std::vector<std::vector<std::string> > res = parition(s);

    for(std::vector<std::vector<std::string> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<std::string>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<res[i][j]<<" ";
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

