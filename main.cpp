#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int titleToNumber(std::string s)
{
    int res = 0;
    for(int i = 0; i < s.size(); ++ i)
        res = res * 26 + (s[i] - 'A' + 1);

    return res;
}


int main()
{
    std::cout<<titleToNumber("AAA")<<std::endl;

    system("pause");
    return 0;
}

