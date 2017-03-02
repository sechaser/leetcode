#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

struct TreeLinkNode
{
    int val;

    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

//void connect(TreeLinkNode* root)
//{
//    if(root == NULL)
//        return;

//    std::queue<TreeLinkNode*> qnode;
//    qnode.push(root);
//    qnode.push(NULL);   //The gap between every level

//    TreeLinkNode* pre = NULL;
//    while(!qnode.empty())
//    {
//        TreeLinkNode* cur = qnode.front();
//        qnode.pop();

//        if(cur != NULL)
//        {
//            if(cur->left)
//                qnode.push(cur->left);
//            if(cur->right)
//                qnode.push(cur->right);
//        }
//        else if(!qnode.empty())
//            qnode.push(NULL);

//        if(pre != NULL)
//            pre->next = cur;

//        pre = cur;
//    }
//}


void connect(TreeLinkNode* root)
{
    /*
     * head: The left most element at next level
     * tail: The right most element at next level
     * now : Current level traveler */
    TreeLinkNode* now, *tail, *head;

    now = root;
    head = tail = NULL;

    while(now)
    {
        if(now->left)
        {
            if(tail)
            {
                tail->next = now->left;
                tail = tail->next;
            }
            else
            {
                tail = now->left;
                head = tail;
            }
        }

        if(now->right)
        {
            if(tail)
            {
                tail->next = now->right;
                tail = tail->next;
            }
            else
            {
                tail = now->right;
                head = tail;
            }
        }

        now = now->next;
        if(!now)
        {
            now = head;
            head = tail = NULL;
        }
    }
}

int main()
{
    TreeLinkNode* node = new TreeLinkNode(1);
    TreeLinkNode* root = node;

    node = new TreeLinkNode(2);
    root->left = node;

    node = new TreeLinkNode(3);
    root->right = node;

    connect(root);

    std::cout<<(root->left->next->val)<<std::endl;

    system("pause");
    return 0;
}

