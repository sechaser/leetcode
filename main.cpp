#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <regex>

bool isMatch(std::string s, std::string p)
{
    int is = 0, ip = 0, istar = -1, starmatch;
    int s_sz = s.size(), p_sz = p.size();

    while(is != s_sz)
    {
        if(ip != p_sz && (s[is] == p[ip] || p[ip] == '?'))
        {
            ++ is;
            ++ ip;
        }
        else if(ip != p_sz && p[ip] == '*')
        {
            istar = ip;
            ++ ip;
            starmatch = is;
        }
        else if(istar != (-1))
        {
            ip = istar + 1;
            ++ starmatch;
            is = starmatch;
        }
        else
            return false;
    }

    while(ip != p_sz && p[ip] == '*')
        ++ ip;

    return ip == p_sz;
}

int main()
{
    std::string s = "", p = "";
    std::cout<<isMatch(s, p)<<std::endl;

    system("pause");
    return 0;
}

