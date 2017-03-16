#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};


int calculate(std::string s)
{
    char sign = '+';
    std::stack<int> stk;
    int num = 0;

    for(int i = 0; i < s.size(); ++ i)
    {
        if(isdigit(s[i]))
            num = 10 * num + (s[i] - '0');

        if((!isdigit(s[i]) && s[i] != ' ') || i == s.size() -1)
        {
            if(sign == '+')
                stk.push(num);
            else if(sign == '-')
                stk.push(-num);
            else
            {
                int tmp = 0;
                if(sign == '*')
                    tmp = stk.top() * num;
                else
                    tmp = stk.top() / num;
                stk.pop();
                stk.push(tmp);
            }

            sign = s[i];
            num = 0;
        }
    }

    int res = 0;

    while(!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main()
{
    std::string s = "3+2*2";
    //calculate(s);
    std::cout<<calculate(s)<<std::endl;

    system("pause");
    return 0;
}

