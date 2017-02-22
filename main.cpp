#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//Time limit exceed
//int divide(int dividend, int divisor)
//{
//    if(divisor == 0 || dividend == 0)
//        return 0;
//    else if(dividend == INT_MIN && divisor == (-1))
//        return INT_MAX;
//    else
//    {
//        int res = 0;
//        bool flag = 0;
//        bool both = 0;

//        if(dividend < 0 && divisor > 0)
//        {
//            dividend = (-dividend);
//            flag     = 1;
//        }
//        else if(dividend > 0 && divisor < 0)
//        {
//            divisor = (-divisor);
//            flag    = 1;
//        }
//        else if(dividend < 0 && divisor < 0)
//        {
//            both = 1;
//            dividend = (-dividend);
//            divisor  = (-divisor);
//        }

//        while(dividend >= divisor)
//        {
//            dividend = dividend - divisor;
//            ++ res;
//        }

//        if(flag)
//            return -res;
//        else
//            return res;
//    }
//}


//int divide(int diviend, int divisor)
//{
//    unsigned int divd = diviend, divs = divisor;
//    if(diviend < 0)
//        divd = (-divd);
//    if(divisor < 0)
//        divs = (-divs);

//    unsigned int res = 0;
//    while(divd >= divs)
//    {
//        long long a = divs;
//        int i;

//        for(i = 1; a <= divd; ++ i)
//            a = (a << 1);

//        res  = res + (1 << (i - 2));
//        divd = divd - (divs << (i - 2));
//    }

//    return (diviend > 0 ^ divisor > 0) ? (-res):(res >= INT_MAX ? INT_MAX : res);
//}


int divide(int diviend, int divisor)
{
    if(divisor == 0)
        return diviend >= 0 ? INT_MAX : INT_MIN;

    if(diviend == INT_MIN && (divisor == (-1)))
        return INT_MAX;

    bool flag = 0;
    if((diviend < 0 && divisor > 0) || (diviend > 0 && divisor < 0))
        flag = 1;

    unsigned long long divid = std::abs((long long)diviend);
    unsigned long long divis = std::abs((long long)divisor);

    int res = 0;

    while(divid >= divis)
    {
        unsigned long long a = divis;

        int i;
        for(i = 0; a <= divid; ++ i)
            a <<= 1;

        res   += (1 << (i-1));
        divid -= (divis << (i-1));
    }

    return flag ? -res : res;
}

int main()
{
    int diviend = -2147483548, divisor = -1;
    int res = divide(diviend, divisor);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

