#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


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

