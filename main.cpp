#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::vector<int> > spiralOrder(int n)
{
    std::vector<std::vector<int> > res;
    if(n <= 0)
        return res;

    res = std::vector<std::vector<int> >(n, std::vector<int>(n, 0));
    int ring = (n + 1) / 2;
    int cborder = n, rborder = n;

    int count = 1;
    for(int i = 0; i != ring; ++ i, cborder -= 2, rborder -= 2)
    {
        for(int j = i; j != i + cborder; ++ j)
        {
            res[i][j] = count;
            ++ count;
        }

        for(int j = i+1; j != i + rborder; ++ j)
        {
            res[j][i+cborder-1] = count;
            ++ count;
        }

        if(cborder == 1 || rborder == 1)
            break;

        for(int j = i + cborder - 2; j >= i; -- j)
        {
            res[i+rborder-1][j] = count;
            ++ count;
        }

        for(int j = i + rborder - 2; j > i; -- j)
        {
            res[j][i] = count;
            ++ count;
        }
    }

    return res;
}

int main()
{
    int n = 3;
    std::vector<std::vector<int> > res = spiralOrder(n);

    for(std::vector<std::vector<int> >::size_type i = 0; i != n; ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != n; ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

