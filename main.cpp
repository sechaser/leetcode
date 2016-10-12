#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string prefix = "";
    if(strs.empty())
        return prefix;
    else
    {
        std::string::size_type minLen = strs[0].size();
        for(std::vector<std::string>::size_type t = 0; t != strs.size(); ++ t)
        {
            if(strs[t].size() < minLen)
                minLen = strs[t].size();
        }

        char ch;
        for(std::string::size_type len = 0; len != minLen; ++ len)
        {
            ch = strs[0][len];
            for(std::vector<std::string>::size_type t = 1; t != strs.size(); ++ t)
            {
                if(strs[t][len] != ch)
                    return prefix;
                else
                    continue;
            }
            prefix += ch;
        }
    }
    return prefix;
}

int main()
{
    std::vector<std::string> strs = {"hello", "h1l", "hellllo"};
    std::string res = longestCommonPrefix(strs);
    std::cout<<res<<std::endl;

    return 0;
}

