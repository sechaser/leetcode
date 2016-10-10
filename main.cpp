#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrome(int x)
{
    std::string str;
    std::stringstream ss;
    while(x != 0)
    {
        ss<<(x % 10);
        x = x / 10;
    }

    for(int i = ss.str().size() - 1; i >= 0; -- i)
        str += ss.str()[i];

    std::string::size_type sz = str.size();
    for(std::string::size_type i = 0; i != sz/2; ++ i)
    {
        if(str[i] == str[sz-i-1])
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    std::stringstream ss;
    int x = 121;
    bool res = isPalindrome(x);

    std::cout<<res<<std::endl;
    system("pause");
    return 0;
}

