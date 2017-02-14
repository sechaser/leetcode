#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


/* Method 1: Time limit exceed */
//void solver(std::string s, int pos, std::vector<std::vector<bool> >& dp, int& curLen, int& res)
//{
//    if(pos == s.size())
//    {
//        if(curLen < res)
//            res = curLen;
//        return;
//    }

//    for(int i = pos; i != s.size(); ++ i)
//    {
//        if(dp[pos][i])
//        {
//            ++ curLen;
//            solver(s, i+1, dp, curLen, res);
//            -- curLen;
//        }
//    }
//}

//int minCut(std::string s)
//{
//    if(s.size() == 0)
//        return 0;

//    int sz = s.size();

//    //Each character is a palindrome, (sz-1) cuts.
//    int res = sz - 1;
//    std::vector<std::vector<bool> > dp(sz, std::vector<bool>(sz, 0));

//    for(int i = sz-1; i >= 0; -- i)
//    {
//        for(int j = i; j < sz; ++ j)
//        {
//            if((s[i] == s[j]) && ((j-i<=2) || dp[i+1][j-1]))
//                dp[i][j] = 1;
//        }
//    }

//    int curLen = (-1);
//    solver(s, 0, dp, curLen, res);

//    return res;
//}


int minCut(std::string s)
{
    if(s.size() == 0)
        return 0;

    int sz = s.size();

    //Each character is a palindrome, (sz-1) cuts.
    std::vector<std::vector<bool> > dp(sz, std::vector<bool>(sz, 0));

    for(int i = sz-1; i >= 0; -- i)
    {
        for(int j = i; j < sz; ++ j)
        {
            if((s[i] == s[j]) && ((j-i<=2) || dp[i+1][j-1]))
                dp[i][j] = 1;
        }
    }

    std::vector<int> res(sz+1, INT_MAX);
    res[0] = -1;
    for(int i = 1; i <= sz; ++ i)
    {
        for(int j = i-1; j >= 0; -- j)
        {
            if(dp[j][i-1])
                res[i] = std::min(res[i], res[j] + 1);
        }
    }

    return res[sz];
}

int main()
{
    std::string s = "bbb";
    std::cout<<minCut(s)<<std::endl;

    system("pause");
    return 0;
}

