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


ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL)
        return head;

    ListNode* curr = head->next;
    ListNode* prev = head;

    while(curr != NULL)
    {
        if(curr->val == prev->val)
        {
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}


int main()
{
    ListNode* node, *p, *lis1;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i;
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

    p = deleteDuplicates(lis1);
    while(p != NULL)
    {
        std::cout<<p->val<<std::endl;
        p = p->next;
    }


    system("pause");
    return 0;
}

