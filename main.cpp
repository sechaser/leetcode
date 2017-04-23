#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

//std::string convertToTitle(int n)
//{
//    return n == 0 ? "" : convertToTitle((n-1)/26) + (char)((n-1)%26 + 'A');
//}

std::string convertToTitle(int n)
{
    std::string res;
    while(n)
    {
        res.push_back((char)((n-1)%26 + 'A'));
        n = (n-1) / 26;
    }

    std::reverse(res.begin(), res.end());

    return res;
}

int main()
{
    std::cout<<convertToTitle(2)<<std::endl;

    system("pause");
    return 0;
}

