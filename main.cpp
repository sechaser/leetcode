#include <iostream>
#include <regex>

bool isMatch(std::string s, std::string p)
{
    std::regex pattern(p);

    if(std::regex_match(s, pattern))
        return true;
    else
        return false;
}

int main()
{
    std::string p = "c*a*b";
    std::string s = "aab";
    bool res;
    res = isMatch(s, p);
    std::cout<<res<<std::endl;

    return 0;
}

