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

int countSegments(std::string s)
{
    s.push_back(' ');
    int counter = 0;
    int i = 0;

    while(i < s.size())
    {
        while(i < s.size() && s[i] == ' ')
            ++ i;

        while(i < s.size() && s[i] != ' ')
            ++ i;

        ++ counter;
    }

    return counter-1;
}

int main()
{
    std::string s = "  ";
    std::cout<<countSegments(s)<<std::endl;

    system("pause");
    return 0;
}

