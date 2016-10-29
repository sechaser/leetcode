#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


//****************************************************逐位相乘处理进位法*****************************************************
//std::string multiply(std::string num1, std::string num2)
//{
//    if(num1.empty() || num2.empty())
//        return "";

//    //Transform string into int
//    std::vector<int> iv1, iv2;
//    int t;
//    for(t = num1.size() - 1; t >= 0; -- t)
//        iv1.push_back(num1[t] - '0');
//    for(t = num2.size() - 1; t >= 0; -- t)
//        iv2.push_back(num2[t] - '0');


//    std::vector<int> res(num1.size()+num2.size(), 0);
//    for(int i = 0; i != iv1.size(); ++ i)
//    {
//        for(int j = 0; j != iv2.size(); ++ j)
//            res[i+j] += (iv1[i] * iv2[j]);
//    }

//    //res[0] need not to be considered.
//    for(int i = res.size() - 1; i >= 1; -- i)
//    {
//        if(res[i] != 0)
//            break;
//        else
//            res.pop_back();
//    }

//    int c = 0;
//    for(int i = 0; i != res.size(); ++ i)
//    {
//        res[i] += c;
//        c = res[i] / 10;
//        res[i] = res[i] % 10;
//    }

//    if(c != 0)
//        res.push_back(c);

//    std::stringstream ss;
//    for(int i = res.size() - 1; i >= 0; -- i)
//        ss<<res[i];

//    return ss.str();
//}


//********************************************************移位进位法**************************************************************
//std::string multiply(std::string num1, std::string num2)
//{
//    if(num1.empty() || num2.empty())
//        return "";

//    std::string res(num1.size() + num2.size(), '0');
//    std::reverse(num1.begin(), num1.end());
//    std::reverse(num2.begin(), num2.end());

//    for(int j = 0; j != num2.size(); ++ j)
//    {
//        int carry = 0;
//        for(int i = 0; i != num1.size(); ++ i)
//        {
//            carry = carry + (num1[i]-'0') * (num2[j]-'0') + (res[i+j]-'0');
//            res[i+j] = carry%10 + '0';
//            carry /= 10;
//        }
//        if(carry)
//            res[num1.size()+j] = carry + '0';
//    }

//    int i = res.size() - 1;
//    while(i >= 1 && res[i] == '0')
//    {
//        res.pop_back();
//        -- i;
//    }
//    std::reverse(res.begin(), res.end());

//    return res;
//}


//不需一开始逆转字符串
std::string multiply(std::string num1, std::string num2)
{
    if(num1.empty() || num2.empty())
        return "";

    std::string res(num1.size() + num2.size(), '0');
    std::string::size_type num1_sz = num1.size();
    std::string::size_type num2_sz = num2.size();

    for(int j = num2.size() - 1; j >= 0; -- j)
    {
        int  carry = 0;
        for(int i = num1.size() - 1; i >= 0; -- i)
        {
            carry = carry + (num1[i] - '0') * (num2[j] - '0') + (res[(num1_sz-1)-i+(num2_sz-1)-j] - '0');
            res[(num1_sz-1)-i+(num2_sz-1)-j] = (carry % 10) + '0';
            carry = carry / 10;
        }

        if(carry)
            res[num1.size() + (num2_sz - 1) - j] = carry + '0';
    }

    int i = res.size() - 1;
    while(i >= 1 && res[i] == '0')
    {
        res.pop_back();
        -- i;
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    std::string num1 = "99", num2 = "99";

    std::string res = multiply(num1, num2);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

