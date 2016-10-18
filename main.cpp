#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int strStr(std::string haystack, std::string needle)
{
    std::string::size_type index;
    if((index = haystack.find(needle)) != std::string::npos)
        return index;
    else
        return (-1);
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

