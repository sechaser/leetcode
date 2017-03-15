#include <iostream>
#include <vector>
#include <string>


//**************************************Method 2 ***************************************
//std::string longestPalidrome(std::string s)
//{
//    if(s.size() <= 1)
//        return s;

//    int maxLen = 0;
//    std::string res = "";
//    int left, right;
//    for(int i = 0; i < 2 * s.size() - 1; ++ i)
//    {
//        left  = i / 2;
//        right = i / 2;

//        if(i % 2 == 1)        //i is the index of the gap
//            ++ right;
//        while(left >= 0 && right < s.size() && s[left] == s[right])
//        {
//            -- left;
//            ++ right;
//        }
//        std::string str = s.substr(left + 1, right - left - 1);

//        if(maxLen < str.size())
//        {
//            maxLen = str.size();
//            res = str;
//        }
//    }

//    return res;
//}


//*******************************************Method 3 : Dynamic Programming************************************
//std::string longestPalidrome(std::string s)
//{
//    if(s.size() <= 1)
//        return s;

//    bool plain[s.size()][s.size()];
//    std::string res;
//    int maxLen = 0;

//    for(int i = s.size() - 1; i >= 0; -- i)
//    {
//        for(int j = i; j != s.size(); ++ j)
//        {
//            if(s[i] == s[j] && ((j - i <= 2) || plain[i+1][j-1]))
//            {
//                plain[i][j] = true;
//                if(maxLen < j - i + 1)
//                {
//                    maxLen = j - i + 1;
//                    res = s.substr(i, maxLen);
//                }
//            }
//        }
//    }

//    return res;
//}


std::string longestPalidrome(std::string s)
{
    if(s.size() <= 1)
        return s;

    std::vector<std::vector<bool> > dp(s.size(), std::vector<bool>(s.size(), 0));
    std::string res;

    for(int i = 0; i < s.size(); ++ i)
    {
        for(int j = 0; j <= i; ++ j)
        {
            if(s[i] == s[j] && ((i-j <= 2 || dp[j+1][i-1])))
            {
                dp[j][i] = 1;
                if(i - j + 1 > res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
    }

//    for(int i = 0; i < s.size(); ++ i)
//    {
//        for(int j = 0; j < s.size(); ++ j)
//            std::cout<<dp[i][j]<<" ";
//        std::cout<<std::endl;
//    }

    return res;
}


int main()
{
    std::string s = "aaaa";
    std::string res = longestPalidrome(s);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

