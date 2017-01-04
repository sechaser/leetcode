#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>


bool isPalidrome(std::string s)
{
    if(s.empty())
        return true;

    std::string::size_type low = 0, high = s.size() - 1;

    while(low < high)
    {
        if(!isalnum(s[low]))
        {
            ++ low;
            continue;
        }
        else if(!isalnum(s[high]))
        {
            -- high;
            continue;
        }
        else
        {
            if(tolower(s[low]) == tolower(s[high]))
            {
                ++ low;
                -- high;
                continue;
            }
            else
                return false;
        }
    }

    return true;
}

int main()
{
    std::string s = "1234 321";

    std::cout<<isPalidrome(s)<<std::endl;

    system("pause");
    return 0;
}

