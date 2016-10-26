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


//************************************Method 2********************************
std::string countAndSay(int n)
{
    if(n < 1)
        return "";
    std::string prev = "1";

    for(int i = 2; i <= n; ++ i)
    {
        char curChar = prev[0];
        int times = 1;
        std::string tmpstr;
        prev.push_back('#');

        for(int k = 1; k < prev.size(); ++ k)
        {
            if(prev[k] == curChar)
                ++ times;
            else
            {
                std::stringstream ss;
                ss<<times;
                tmpstr += ss.str();
                tmpstr.push_back(curChar);

                curChar = prev[k];
                times = 1;
            }
        }

        prev = tmpstr;
    }

    return prev;
}

int main()
{
    std::string res = countAndSay(5);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

