#include <iostream>
#include <vector>
#include <string>

//std::string longestCommonPrefix(std::vector<std::string>& strs)
//{
//    std::string prefix = "";
//    if(strs.empty())
//        return prefix;
//    else
//    {
//        std::string::size_type minLen = strs[0].size();
//        for(std::vector<std::string>::size_type t = 0; t != strs.size(); ++ t)
//        {
//            if(strs[t].size() < minLen)
//                minLen = strs[t].size();
//        }

//        char ch;
//        for(std::string::size_type len = 0; len != minLen; ++ len)
//        {
//            ch = strs[0][len];
//            for(std::vector<std::string>::size_type t = 1; t != strs.size(); ++ t)
//            {
//                if(strs[t][len] != ch)
//                    return prefix;
//                else
//                    continue;
//            }
//            prefix += ch;
//        }
//    }
//    return prefix;
//}


//std::string longestCommonPrefix(std::vector<std::string>& strs)
//{
//    std::string prefix;
//    if(strs.empty())
//        return prefix;

//    /* The length of longest prefix must be euqal to or shorter than the first string*/
//    for(std::string::size_type i = 0; i != strs[0].size(); ++ i)
//    {
//        /* Traver other string*/
//        for(std::vector<std::string>::size_type j = 1; j != strs.size(); ++ j)
//        {
//            if(strs[j].size() == i || strs[j][i] != strs[0][i])
//                return prefix;
//        }
//        prefix += strs[0][i];
//    }

//    return prefix;
//}

int main()
{
    std::vector<std::string> strs = {"hellao", "hellb", "helllo"};
    std::string res = longestCommonPrefix(strs);
    std::cout<<res<<std::endl;

    return 0;
}

