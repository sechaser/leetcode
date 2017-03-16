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


bool repeatedSubstringPattern(std::string s)
{
    int sz = s.size();
    for(int i = sz/2; i > 0; -- i)
    {
        if(sz % i == 0)
        {
            int num = sz / i;
            std::string t;
            for(int j = 0; j < num; ++ j)
                t += s.substr(0, i);

            if(t == s)
                return true;
        }
    }

    return false;
}

int main()
{
    std::string s = "aba";
    std::cout<<repeatedSubstringPattern(s)<<std::endl;

    system("pause");
    return 0;
}

