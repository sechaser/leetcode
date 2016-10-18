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
    if(head == NULL)
        return NULL;

    ListNode* node = new ListNode(0);
    node->next = head;
    ListNode* pre = node;
    ListNode* cur = head;

    while(cur != NULL && cur->next != NULL)
    {
        ListNode* next = cur->next->next;
        cur->next->next = cur;
        pre->next = cur->next;

        if(next != NULL && next->next != NULL)
            cur->next = next->next;
        else
            cur->next = next;

        pre = cur;
        cur = next;
    }

    return node->next;
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

