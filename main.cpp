#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


//void reverseWords(std::string& s)
//{
//    if(s.empty())
//        return;

//    std::string res;
//    int i = s.size() - 1;

//    while(i >= 0)
//    {
//        while(i >= 0 && s[i] == ' ')
//            -- i;

//        if(i < 0)
//            break;

//        if(!res.empty())
//            res.push_back(' ');

//        std::string t;
//        while(i >= 0 && s[i] != ' ')
//        {
//            t.push_back(s[i]);
//            -- i;
//        }
//        std::reverse(t.begin(), t.end());
//        res.append(t);
//    }

//    s = res;
//}



void reverseWords(std::string& s)
{
    if(s.empty())
        return;

    std::stack<std::string> stk;
    int i = 0;

    while(i < s.size())
    {
        while(i < s.size() && s[i] == ' ')
            ++ i;

        if(i == s.size())
            break;

        std::string temp;
        while(i < s.size() && s[i] != ' ')
        {
            temp.push_back(s[i]);
            ++ i;
        }

        if(!temp.empty())
            stk.push(temp);
    }

    std::string result;
    if(stk.empty())
    {
        s = result;
        return;
    }

    while(!stk.empty())
    {
        result = result + " " + stk.top();
        stk.pop();
    }

    result.erase(result.begin());
    s = result;
}

int main()
{
    std::string s = "The sky is blue";
    reverseWords(s);
    std::cout<<s<<std::endl;

    system("pause");
    return 0;
}

