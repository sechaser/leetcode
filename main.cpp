#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

int lengthOfLastWord(std::string s)
{
    if(s.empty())
        return 0;
    std::string::iterator it1 = s.end() - 1;

    //The first character is not ' '.
    while(it1 >= s.begin() && *it1 == ' ')
        -- it1;

    std::string::iterator it2 = it1;
    while(it2 >= s.begin() && *it2 != ' ')
        -- it2;

    return (it1 - it2);
}

int main()
{
    std::string s = "abd we ";
    std::cout<<lengthOfLastWord(s)<<std::endl;

    system("pause");
    return 0;
}

