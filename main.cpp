#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

std::string simplifyPath(std::string path)
{
    std::vector<std::string> res;
    std::string tmp;

    path.push_back('/');
    for(std::string::size_type i = 0; i != path.size(); ++ i)
    {
        if(path[i] == '/')
        {
            if(tmp.empty())
                continue;
            else if(tmp == "..")
            {
                if(!res.empty())
                    res.pop_back();
                tmp.clear();
            }
            else if(tmp == ".")
                tmp.clear();
            else
            {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        else
            tmp.push_back(path[i]);
    }

    std::string str;
    for(std::vector<std::string>::size_type i = 0; i != res.size(); ++ i)
        str = str + "/" + res[i];

    if(res.empty())
        str = "/";

    return str;
}

int main()
{
    std::string path = "/...";
    std::string res  = simplifyPath(path);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

