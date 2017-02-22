#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <utility>

int longestValidParentheses(std::string s)
{
    if(s.empty())
        return 0;
    else
    {
        int maxlen = 0;
        int templen = 0;
        std::stack<int> indexSt;

        for(std::string::size_type i = 0; i != s.size(); ++ i)
        {
            if(s[i] == '(')
                indexSt.push(i);
            else
            {
                if(indexSt.empty() || s[indexSt.top()] != '(')
                    indexSt.push(i);
                else
                {
                    indexSt.pop();
                    if(indexSt.empty())
                        templen = i + 1;
                    else
                        templen = i - indexSt.top();

                    if(templen > maxlen)
                        maxlen = templen;
                }
            }
        }

        return maxlen;
    }
}

int main()
{
    std::string s = "())()()";
    int res = longestValidParentheses(s);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

