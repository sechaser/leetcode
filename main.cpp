#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int nthUglyNumber(int n)
{
    if(n <= 0)
        return 0;

    if(n == 1)
        return 1;

    std::vector<int> res(n, 0);
    res[0] = 1;
    int k2 = 0, k3 = 0, k5 = 0;

    for(int i = 1; i < n; ++ i)
    {
        res[i] = std::min(res[k2]*2, std::min(res[k3]*3, res[k5]*5));

        if(res[i] == res[k2] * 2)
            ++ k2;
        if(res[i] == res[k3] * 3)
            ++ k3;
        if(res[i] == res[k5] * 5)
            ++ k5;
    }

    return res[n-1];
}

int main()
{
    std::cout<<nthUglyNumber(3)<<std::endl;

    system("pause");
    return 0;
}

