#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <queue>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* head)
{
    if(!head)
        return head;
    std::unordered_map<RandomListNode*, RandomListNode*> ht;
    RandomListNode* p2 =  new RandomListNode(head->val);
    ht[head] = p2;

    std::queue<RandomListNode*> q;
    q.push(head);

    while(!q.empty())
    {
        RandomListNode* p1 = q.front();
        p2 = ht[p1];
        q.pop();

        if(p1->next)
        {
            if(ht.count(p1->next))
                p2->next = ht[p1->next];
            else
            {
                RandomListNode* newNode = new RandomListNode(p1->next->label);
                ht[p1->next] = newNode;
                p2->next = newNode;
            }
        }
    }

    return ht[head];
}


int main()
{
    ListNode* node, *p, *lis1, *lis2, *lis3;
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


    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i+5;
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

    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i;
        node->next = NULL;

        if(i == 0)
        {
            lis3 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }


    system("pause");
    return 0;
}

