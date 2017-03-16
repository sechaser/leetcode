#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

bool canConstruct(std::string ransomNote, std::string magazine)
{
    std::unordered_map<char, int> mp;

    for(auto &ch : magazine)
        ++ mp[ch];

    for(auto &ch : ransomNote)
    {
        if(-- mp[ch] < 0)
            return false;
    }
    return true;
}


int main()
{
    std::string ransomNote = "aaa", magazine = "aaba";
    std::cout<<canConstruct(ransomNote, magazine)<<std::endl;

    system("pause");
    return 0;
}

