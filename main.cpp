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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    std::vector<int> v1, v2;
    while(l1)
    {
        v1.push_back(l1->val);
        l1 = l1->next;
    }

    while(l2)
    {
        v2.push_back(l2->val);
        l2 = l2->next;
    }

    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());

    if(v1.size() < v2.size())
    {
        std::vector<int> temp(v2);
        v2 = v1;
        v1 = temp;
    }

    std::vector<int> res(v1.size() + 1, 0);
    int sz = v2.size();

    int i = 0, carry = 0;
    while(i < sz)
    {
        carry = carry + v1[i] + v2[i];
        res[i] = carry % 10;
        carry  = carry / 10;
        ++ i;
    }

    for(i = sz; i < v1.size(); ++ i)
    {
        carry = carry + v1[i];
        res[i] = carry % 10;
        carry  = carry / 10;
    }

    if(carry)
        res[v1.size()] = carry;

    i = res.size() - 1;
    while(i > 0 && res[i] == 0)
    {
        res.pop_back();
        -- i;
    }

    std::reverse(res.begin(), res.end());
    ListNode* dummy = new ListNode(0);
    ListNode* p = dummy;

    for(i = 0; i < res.size(); ++ i)
    {
        ListNode* node = new ListNode(res[i]);
        p->next = node;
        p = p->next;
    }

    return dummy->next;
}


int main()
{
    ListNode* node, *p, *lis1, *lis2;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = 5 - i;
        node->next = NULL;

        if(i == 0)
        {
            lis1 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }


    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i + 5;
        node->next = NULL;

        if(i == 0)
        {
            lis2 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }
    addTwoNumbers(lis1, lis2);


    system("pause");
    return 0;
}

