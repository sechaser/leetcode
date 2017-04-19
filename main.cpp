#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

std::string convertToTitle(int n)
{
    return n == 0 ? "" : convertToTitle((n-1)/26) + (char)((n-1)%26 + 'A');
}

int main()
{
    std::cout<<convertToTitle(52)<<std::endl;

    system("pause");
    return 0;
}

