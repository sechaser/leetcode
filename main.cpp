#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//std::string addBinary(std::string a, std::string b)
//{
//    if(a.empty())
//        return b;
//    else if(b.empty())
//        return a;
//    else
//    {
//        std::string res;
//        if(a.size() < b.size())
//        {
//            std::string tmp = b;
//            b = a;
//            a = tmp;
//        }
//        std::string::size_type asz = a.size(), bsz = b.size();
//        int gap = asz - bsz;

//        bool carry = 0;
//        for(int i = bsz - 1; i >= 0; -- i)
//        {
//            if(a[gap + i] == '1' && b[i] == '1')
//            {
//                if(carry)
//                    res.insert(res.begin(), '1');
//                else
//                {
//                    res.insert(res.begin(), '0');
//                    carry = 1;
//                }
//            }
//            else if(a[gap + i] == '0' && b[i] == '0')
//            {
//                if(carry)
//                {
//                    res.insert(res.begin(), '1');
//                    carry = 0;
//                }
//                else
//                    res.insert(res.begin(), '0');
//            }
//            else
//            {
//                if(carry)
//                    res.insert(res.begin(), '0');
//                else
//                    res.insert(res.begin(), '1');
//            }
//        }


//        if(carry)
//        {
//            for(int i = asz - bsz - 1; i >= 0; -- i)
//            {
//                if(a[i] == '1')
//                {
//                    if(carry)
//                        res.insert(res.begin(), '0');
//                    else
//                        res.insert(res.begin(), '1');
//                }
//                else
//                {
//                    if(carry)
//                    {
//                        res.insert(res.begin(), '1');
//                        carry = 0;
//                    }
//                    else
//                        res.insert(res.begin(), '0');
//                }
//            }
//        }
//        else
//        {
//            for(int i = asz - bsz - 1; i >= 0; -- i)
//                res.insert(res.begin(), a[i]);
//        }

//        if(carry)
//            res.insert(res.begin(), '1');

//        return res;
//    }
//}


std::string addBinary(std::string a, std::string b)
{
    std::string res;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int n = std::max(a.size(), b.size());
    int carry = 0;
    for(int i = 0; i < n; ++ i)
    {
        if(i < a.size())
            carry += (a[i] - '0');
        if(i < b.size())
            carry += (b[i] - '0');

        res.push_back(carry%2+'0');
        carry /= 2;
    }

    if(carry)
        res.push_back('1');
    std::reverse(res.begin(), res.end());

    return res;
}

int main()
{
    std::string a = "1010", b = "1011";
    std::string res = addBinary(a, b);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

