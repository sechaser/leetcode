#include <iostream>
#include <vector>
#include <string>


//*********************Method 1: Brute Force****************************
//std::string longestPalidrome(std::string s)
//{
//    if(s.size() <= 1)
//        return s;

//    std::string str;
//    std::string maxStr;

//    //The length of palidrome string
//    for(std::string::size_type len = 1; len <= s.size(); ++ len)
//    {
//        for(std::string::size_type start = 0; start != (s.size() - len + 1); ++ start)
//        {
//            str = s.substr(start, len);
//            bool flag = 1;
//            //Check if it is palidrome
//            size_t sz = str.size();
//            for(std::string::size_type i = 0; i != sz/2; ++ i)
//            {
//                if(str[i] == str[sz - i - 1])
//                    continue;
//                else
//                {
//                    flag = 0;
//                    break;
//                }
//            }

//            if(flag)
//                maxStr = str;
//        }
//    }

//    return maxStr;
//}


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
std::string longestPalidrome(std::string s)
{
    if(s.size() <= 1)
        return s;

    bool plain[s.size()][s.size()];
    std::string res;
    int maxLen = 0;

    for(int i = s.size() - 1; i >= 0; -- i)
    {
        for(int j = i; j != s.size(); ++ j)
        {
            if(s[i] == s[j] && ((j - i <= 2) || plain[i+1][j-1]))
            {
                plain[i][j] = true;
                if(maxLen < j - i + 1)
                {
                    maxLen = j - i + 1;
                    res = s.substr(i, maxLen);
                }
            }
        }
    }

    return res;
}

//std::vector<std::string> longestPalidrome(std::string s)
//{
//    std::vector<std::string> res;
//    if(s.size() <= 1)
//    {
//        res.push_back(s);
//        return res;
//    }

//    int maxLen = 0;
//    int left, right;

//    for(int i = 0; i < 2 * s.size() - 1; ++ i)
//    {
//        left  = i / 2;
//        right = i / 2;

//        if(i % 2 == 1)        // now i is the index of the gap
//            ++ right;         // let the right is the index of the character right of the gap.
//        while(left >= 0 && right < s.size() && s[left] == s[right])
//        {
//            -- left;
//            ++ right;
//        }
//        std::string str = s.substr(left + 1, right - left - 1);

//        if(maxLen < str.size())
//        {
//            res.clear();
//            res.push_back(str);
//            maxLen = str.size();
//        }
//        else if (maxLen == str.size())
//            res.push_back(str);
//        else
//            continue;
//    }

//    return res;
//}


int main()
{
    std::string s = "aaaaaaaabbbbbb";
    std::string res = longestPalidrome(s);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

