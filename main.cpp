#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s)
{
    std::stack<char> stac;
    std::string::size_type sz = s.size();

    for(std::string::size_type i = 0; i != sz; ++ i)
    {
        if(stac.empty())
            stac.push(s[i]);
        else if((stac.top() == '(' && s[i]== ')') || (stac.top() == '[' && s[i]== ']') || (stac.top() == '{' && s[i]== '}'))
            stac.pop();
        else
            stac.push(s[i]);
    }

    if(stac.empty())
        return true;
    else
        return false;
}

int main()
{
    std::string s = "[()]";
    bool res = isValid(s);
    std::cout<<res<<std::endl;

    return 0;
}

