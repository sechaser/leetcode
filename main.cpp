#include <iostream>
#include <string>

#include <math.h>

int main()
{
    std::string s = "aabbca";
    int maxLen = 0, startIndex = 0;

    if((s.size() == 0) || (s.size() == 1) )
        return s.size();

    for(std::string::size_type i = 1; i != s.size(); ++ i)
    {
        std::string::size_type j;
        for(j = startIndex; j != i; ++ j)
        {
            if(s[j] != s[i])
                continue;
            else
            {
                if(i - startIndex > maxLen)
                    maxLen = i - startIndex;
                startIndex = j + 1;
                break;
            }
        }
        if(j == i)
        {
            if(i - startIndex >= maxLen)
                maxLen = i - startIndex + 1;
        }
    }
    std::cout<<"maxlen = "<<maxLen<<std::endl;

    system("pause");
    return 0;
}

