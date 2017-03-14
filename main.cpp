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

std::string reverseStr(std::string s, int k)
{
    if(s.empty())
        return s;

    if(s.size() <= k)
    {
        std::reverse(s.begin(), s.end());
        return s;
    }

    int group = s.size() / (k * 2);
    for(int i = 0; i != group; ++ i)
    {
        int left = i * 2 * k, right = i * 2 * k + k - 1;
        while(left < right)
        {
            char ch = s[left];
            s[left] = s[right];
            s[right] = ch;

            -- right;
            ++ left;
        }
    }

    int left, right;
    if(s.size() - group * 2 * k <= k)
    {
        left = group * 2 * k;
        right = s.size() - 1;
    }
    else
    {
        left  = group * 2 * k;
        right = group * 2 * k + k - 1;
    }

    while(left < right)
    {
        char ch = s[left];
        s[left] = s[right];
        s[right] = ch;

        -- right;
        ++ left;
    }

    return s;
}

int main()
{
    std::string s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    std::string res = reverseStr(s, 39);

    system("pause");
    return 0;
}

