#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<int> grayCode(int n)
{
    std::vector<int> gray;
    gray.push_back(0);
    int inc = 1;

    for(int i = 1; i <= n; ++ i)
    {
        for(int j = gray.size() - 1; j >= 0; -- j)
            gray.push_back(gray[j] + inc);

        inc <<= 1;
    }

    return gray;
}


int main()
{
    std::vector<int> gray = grayCode(3);
    for(std::vector<int>::size_type i = 0; i != gray.size(); ++ i)
        std::cout<<std::setw(4)<<gray[i];
    std::cout<<std::endl;



    system("pause");
    return 0;
}

