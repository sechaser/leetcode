#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int trailingZeroes(int n)
{
    return n==0? 0 : n/5 + trailingZeroes(n/5);
}

int main()
{


    system("pause");
    return 0;
}

