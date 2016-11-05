#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isNumber(std::string s)
{
    bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
    int n = s.size();

    for(int i = 0; i < n; ++ i)
    {
        //Space
        std::cout<<"s[i] = "<<s[i]<<std::endl;
        if(s[i] == ' ')
        {
            if(i < n - 1 && s[i+1] != ' ' && (num || dot || exp || sign))
                return false;
            std::cout<<"num="<<num<<",numAfterE="<<numAfterE<<",dot="<<dot<<",exp="<<exp<<",sign="<<sign<<std::endl;
        }
        //Sign
        else if(s[i] == '+' || s[i] == '-')
        {
            if(i > 0 && (s[i-1] != 'e') && s[i-1] != ' ')
                return false;
            sign = true;
            std::cout<<"num="<<num<<",numAfterE="<<numAfterE<<",dot="<<dot<<",exp="<<exp<<",sign="<<sign<<std::endl;
        }
        //Digit
        else if(s[i] >= '0' && s[i] <= '9')
        {
            num = true;
            numAfterE = true;
            std::cout<<"num="<<num<<",numAfterE="<<numAfterE<<",dot="<<dot<<",exp="<<exp<<",sign="<<sign<<std::endl;
        }
        //Dot
        else if(s[i] == '.')
        {
            if(dot || exp)
                return false;
            dot = true;
            std::cout<<"num="<<num<<",numAfterE="<<numAfterE<<",dot="<<dot<<",exp="<<exp<<",sign="<<sign<<std::endl;
        }
        //Exp
        else if(s[i] == 'e' || s[i] == 'E')
        {
            if(exp || !num)
                return false;
            exp = true;
            numAfterE = false;
            std::cout<<"num="<<num<<",numAfterE="<<numAfterE<<",dot="<<dot<<",exp="<<exp<<",sign="<<sign<<std::endl;
        }
        else
            return false;
    }

    return num && numAfterE;
}

int main()
{
    std::string s = " 005047e+6";
    std::cout<<isNumber(s)<<std::endl;

    system("pause");
    return 0;
}

