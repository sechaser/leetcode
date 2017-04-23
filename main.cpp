#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isUgly(int num)
{
    if(num == 0)
        return 0;

    while(num % 2 == 0)
        num /= 2;

    while(num % 3 == 0)
        num /= 3;

    while(num % 5 == 0)
        num /= 5;

    return num == 1 ? 1 : 0;
}

int main()
{
    std::cout<<isUgly(14)<<std::endl;

    system("pause");
    return 0;
}

