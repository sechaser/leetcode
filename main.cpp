#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

void reverseWords(std::string& s)
{
    if(s.empty())
        return;

    std::string res;
    int i = s.size() - 1;

    while(i >= 0)
    {
        while(i >= 0 && s[i] == ' ')
            -- i;

        if(i < 0)
            break;

        if(!res.empty())
            res.push_back(' ');

        std::string t;
        while(i >= 0 && s[i] != ' ')
        {
            t.push_back(s[i]);
            -- i;
        }
        std::reverse(t.begin(), t.end());
        res.append(t);
    }

    s = res;
}

int main()
{
    std::string s = "The sky is blue";
    reverseWords(s);
    std::cout<<s<<std::endl;

    system("pause");
    return 0;
}

