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

bool isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

std::string reverseVowels(std::string s)
{
    if(s.empty())
        return s;

    int left = 0, right = s.size() - 1;

    while(left < right)
    {
        while(left < right && !isVowel(tolower(s[left])))
            ++ left;

        while(left < right && !isVowel(tolower(s[right])))
            -- right;

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        ++ left;
        -- right;
    }

    return s;
}

int main()
{
    std::string s = "leetcode";
    std::string res = reverseVowels(s);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

