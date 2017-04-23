#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int addDigits(int num)
{
    if(num < 10)
        return num;

    while(num >= 10)
    {
        int res = 0;
        std::string temp = std::to_string(num);
        for(int i = 0; i < temp.size(); ++ i)
            res += (temp[i] - '0');

        num = res;
    }

    return num;
}


int main()
{
    std::cout<<addDigits(111)<<std::endl;

    system("pause");
    return 0;
}

