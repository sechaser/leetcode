#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isPowerOfTwo(int n)
{
    if(n <= 0)
        return false;

    bool ans = n & (n-1);
    return !ans;
}


int main()
{
    std::cout<<isPowerOfTwo(5)<<std::endl;

    system("pause");
    return 0;
}

