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


bool hasCycle(ListNode* head)
{
    if(!head)
        return false;
    ListNode* fast = head, *low = head;

    do
    {
        if((!fast->next) || (!fast->next->next))
            return false;

        fast = fast->next->next;
        low = low->next;
    }while(low != fast);

    return true;
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
    p->next = lis1;

    std::cout<<hasCycle(lis1)<<std::endl;


    system("pause");
    return 0;
}

