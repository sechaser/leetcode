#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


//************************************Method 1***************************************
//std::string countAndSay(int n)
//{
//    if(n < 1)
//        return "";

//    std::string res = "1";

//    for(int i = 2; i <= n; ++ i)
//    {
//        int count;
//        char ch;
//        std::string temp;
//        int j;
//        for(j = 0; j != res.size(); ++ j)
//        {
//            if(j == 0)
//            {
//                count = 1;
//                ch = res[0];
//            }
//            else
//            {
//                if(res[j] == ch)
//                    ++ count;
//                else
//                {
//                    std::stringstream ss;
//                    ss<<count;
//                    temp += ss.str();
//                    temp.push_back(ch);

//                    ch = res[j];
//                    count = 1;
//                }
//            }
//        }

//        if(count)
//        {
//            std::stringstream ss;
//            ss<<count;
//            temp += ss.str();
//            temp.push_back(ch);
//        }
//        res = temp;
//    }

//    return res;
//}

std::string countAndSay(int n)
{
    if(n <= 0)
        return "";

    std::string res = "1";
    int count = 0;
    char ch;
    for(int i = 2; i <= n; ++ i)
    {
        std::string tmp;
        ch = res[0];
        count = 1;

        for(int j = 1; j != res.size(); ++ j)
        {
            if(res[j] == ch)
                ++ count;
            else
            {
                tmp += std::to_string(count);
                tmp += ch;

                ch = res[j];
                count = 1;
            }
        }

        tmp += std::to_string(count);
        tmp += ch;
        res = tmp;
    }

    return res;
}

int main()
{
    std::string res = countAndSay(4);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

