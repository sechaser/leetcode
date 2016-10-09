#include <iostream>
#include <algorithm>

#include <math.h>

int reverse(int x)
{
    int res = 0;
    while(x != 0)
    {
        if(res > INT_MAX / 10 || res < INT_MIN / 10)
            return 0;
        res = res * 10 + x % 10;
        x = x / 10;
    }

    return res;
}

int main()
{
    int x = 1111111115;
    int res = reverse(x);
    std::cout<<res<<std::endl;
    std::cout<<INT_MAX<<" "<<INT_MIN<<std::endl;

    std::cout<<pow(2, 31)<<std::endl;

    return 0;
}

