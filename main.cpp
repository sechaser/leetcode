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

bool detectCapitalUse(std::string word)
{
    if(word.empty())
        return false;

    bool lower = islower(word[0]) ? true : false;
    if(lower)
    {
        for(int i = 1; i < word.size(); ++ i)
        {
            if(!islower(word[i]))
                return false;
        }
    }
    else
    {
        if(word.size() == 1)
            return true;

        bool lower2 = islower(word[1]) ? true : false;
        for(int i = 2; i < word.size(); ++ i)
        {
            if((lower2 && !islower(word[i])) || (!lower2 && islower(word[i])))
                return false;
        }
    }

    return true;
}

int main()
{
    std::string word = "UA";
    std::cout<<detectCapitalUse(word)<<std::endl;


    system("pause");
    return 0;
}

