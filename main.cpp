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


ListNode* swapPairs(ListNode* head)
{
    if(!head)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* pre = dummy, *cur = head;

    while(cur && cur->next)
    {
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = cur;

        pre = cur;
        cur = cur->next;
    }

    return dummy->next;
}

int main()
{
    ListNode* list1, *node, *p;

    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->next = NULL;
        node->val  = i;

        if(i == 0)
        {
            list1 = node;
            p     = node;
        }
        else
        {
            p->next = node;
            p       = p->next;
        }
    }

    ListNode* newList = swapPairs(list1);
    while(newList != NULL)
    {
        std::cout<<std::setw(4)<<newList->val;
        newList = newList->next;
    }
    std::cout<<std::endl;

    system("pause");
    return 0;
}

