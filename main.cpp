#include <iostream>
#include <string>

std::string convert(std::string s, int numRows)
{
    if(numRows == 1)
        return s;

    std::string res = "";
    int interval = 2 * numRows - 2;

    //First row
    int i;
    for(i = 0; i < s.size(); i = i + interval)
        res += s[i];


    //Middle row
    for(i = 1; i != numRows - 1; ++ i)
    {
        int inter = 2 * i;
        for(int j = i; j < s.size(); j = j + inter)
        {
            res += s[j];
            inter = interval - inter;
        }
    }

//    bool flag;
//    for(i = 1; i != numRows - 1; ++ i)
//    {
//        int j = i;
//        flag = 0;
//        while(j < s.size())
//        {
//            res += s[j];
//            if(!flag)
//            {
//                j += (interval - 2 * i);
//                flag = 1;
//            }
//            else
//            {
//                j += (2 * i);
//                flag = 0;
//            }
//        }
//    }

    //Last row
    for(i = numRows - 1; i < s.size(); i = i + interval)
        res += s[i];

    return res;
}

int main()
{
    std::string s = "ABCDE";
    std::string str = convert(s, 4);
    std::cout<<str<<std::endl;

    return 0;
}

