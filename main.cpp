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

std::string reverseString(std::string s)
{
    std::reverse(s.begin(), s.end());
    return s;
}

int main()
{


    system("pause");
    return 0;
}

