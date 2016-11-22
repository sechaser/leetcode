#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int> > zigzagLevelOrder(TreeNode* root)
{
    std::vector<std::vector<int> > res;
    if(root == NULL)
        return res;

    std::queue<TreeNode*> qnode;
    qnode.push(root);
    qnode.push(NULL);

    bool flag = 0;
    std::vector<int> level;
    while(!qnode.empty())
    {
        TreeNode* tmp = qnode.front();
        qnode.pop();

        if(tmp != NULL)
        {
            level.push_back(tmp->val);
            if(tmp->left)
                qnode.push(tmp->left);
            if(tmp->right)
                qnode.push(tmp->right);
        }
        else
        {
            if(flag)
                std::reverse(level.begin(), level.end());

            res.push_back(level);
            flag = !flag;

            if(!qnode.empty())
            {
                level.clear();
                qnode.push(NULL);
            }
        }
    }

    return res;
}

int main()
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 1;
    node->left = NULL;
    node->right = NULL;

    TreeNode* root = node;

    node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 2;
    node->left = NULL;
    node->right = NULL;

    root->right = node;

    node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 3;
    node->left = NULL;
    node->right = NULL;

    root->left = node;


    system("pause");
    return 0;
}

