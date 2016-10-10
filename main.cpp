#include <iostream>
#include <algorithm>
#include <string>

int myAtoi(std::string str)
{
    if(str.size() == 0)
        return 0;

    double res = 0;
    bool signal = 0, positive = 1;
    std::string s;

    std::string::size_type j = 0;
    while(str[j] == ' ')
        ++ j;

    for(std::string::size_type i = j; i != str.size(); ++ i)
    {
        if(str[i] == '+')
        {
            if(signal)
                break;
            else
                signal = 1;
        }
        else if(str[i] == '-')
        {
            if(signal)
                break;
            else
            {
                positive = 0;
                signal = 1;
            }
        }
        else if(!isdigit(str[i]))
            break;
        else
        {
            s = str.substr(i, 1);
            res = 10 * res + atoi(s.c_str());
        }
    }

    if(positive)
    {
        if(res > INT_MAX)
            return INT_MAX;
        else
            return res;
    }
    else
    {
        if((-res) < INT_MIN)
            return INT_MIN;
        else
            return (-res);
    }
}

int main()
{
    std::string str = "922337203684775809";
    int res = myAtoi(str);

    std::cout<<res<<std::endl;
    std::cout<<INT_MAX<<" "<<INT_MIN<<std::endl;

    system("pause");
    return 0;
}

