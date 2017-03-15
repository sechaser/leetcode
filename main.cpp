#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isValid(std::string str)
{
    if(str[0] == '0' && str.size() > 1)
        return false;

    if(std::stoi(str) > 255)
        return false;

    return true;
}

void solver(std::string& s, int beg, std::vector<std::string>& tmp, std::vector<std::string>& res)
{
    if(tmp.size() == 4)
    {
        if(beg == s.size())
        {
            std::string str = tmp[0];
            for(int i = 1; i != tmp.size(); ++ i)
                str = str + "." + tmp[i];
            res.push_back(str);
        }
        return;
    }

    std::string part;
    for(int i = beg; i != s.size() && i < beg + 3; ++ i)
    {
        part.push_back(s[i]);

        if(isValid(part))
        {
            tmp.push_back(part);
            solver(s, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
}

std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::vector<std::string> res;
    std::vector<std::string> tmp;

    solver(s, 0, tmp, res);

    return res;
}



int main()
{
    std::string s = "25525511135";
    std::vector<std::string> res = restoreIpAddresses(s);

    for(std::vector<std::string>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;
    std::cout<<std::endl;

    system("pause");
    return 0;
}

