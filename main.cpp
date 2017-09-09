#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//int strStr(std::string haystack, std::string needle)
//{
//    std::string::size_type index;
//    if((index = haystack.find(needle)) != std::string::npos)
//        return index;
//    else
//        return (-1);
//}

int strStr(std::string haystack, std::string needle)
{
    if(needle.size() == 0)
        return 0;
    if(haystack.size() == 0)
        return -1;

    int m = haystack.size(), n = needle.size();
    if(m < n)
        return -1;

    for(int i = 0; i <= m-n; ++ i)
    {
        if(haystack.substr(i, n) == needle)
            return i;
    }

    return -1;
}

int strStr(std::string haystack, std::string needle)
{
    if(needle.size() == 0)
        return 0;
    if(haystack.size() == 0)
        return -1;

    int m = haystack.size(), n = needle.size();
    for(int i = 0; i <= (m-n); ++ i)
    {
        bool flag = 1;
        for(int j = 0; j != n; ++ j)
        {
            if(haystack[i+j] != needle[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return i;
    }

    return -1;
}

int main()
{
    std::string haystack = "abcdefg";
    std::string needle   = "bcf";

    int res = strStr(haystack, needle);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

