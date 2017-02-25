#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//二分法
int mySqrt(int x)
{
    if(x <= 0)
        return 0;
    int l = 0, r = x/2 + 1;
    long long m;

    while(l <= r)
    {
        m = (l + r) / 2;

        if(m * m  == x)
            return m;
        else if(m * m < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return r;
}

//牛顿法
int mySqrt(int x)
{
    if(x == 0)
        return 0;

    double x1 = 0;
    double x2 = x/2.0 + 1;

    while(x1 != x2)
    {
        x1 = x2;
        x2 = (x1 + x/x1) / 2.0;
    }

    return (int)x2;
}

int main()
{
    std::cout<<mySqrt(135)<<std::endl;

    system("pause");
    return 0;
}

