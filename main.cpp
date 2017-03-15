#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::string addBinary(std::string a, std::string b)
{
    if(a.empty() && b.empty())
        return a;

    if(a.empty())
        return b;
    if(b.empty())
        return a;

    if(a.size() < b.size())
    {
        std::string tmp(a);
        a = b;
        b = tmp;
    }

    int sz = b.size();
    std::string res(a.size() + 1, '0');

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int carry = 0;
    for(int i = 0; i < b.size(); ++ i)
    {
        carry = carry + (a[i] - '0') + (b[i] - '0');
        res[i] = carry % 2 + '0';
        carry = carry / 2;
    }

    for(int i = b.size(); i < a.size(); ++ i)
    {
        carry = carry + (a[i] - '0');
        res[i] = carry % 2 + '0';
        carry = carry / 2;
    }

    if(carry)
        res[a.size()] = carry + '0';
    else
        res.pop_back();

    std::reverse(res.begin(), res.end());

    return res;
}


//std::string addBinary(std::string a, std::string b)
//{
//    std::string res;
//    std::reverse(a.begin(), a.end());
//    std::reverse(b.begin(), b.end());

//    int n = std::max(a.size(), b.size());
//    int carry = 0;
//    for(int i = 0; i < n; ++ i)
//    {
//        if(i < a.size())
//            carry += (a[i] - '0');
//        if(i < b.size())
//            carry += (b[i] - '0');

//        res.push_back(carry%2+'0');
//        carry /= 2;
//    }

//    if(carry)
//        res.push_back('1');
//    std::reverse(res.begin(), res.end());

//    return res;
//}

int main()
{
    std::string a = "1010", b = "1011";
    std::string res = addBinary(a, b);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

