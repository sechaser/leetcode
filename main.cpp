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


std::vector<std::vector<int> > levelOrder(TreeNode* root)
{
    std::vector<std::vector<int> > res;
    if(root == NULL)
        return res;

    std::queue<TreeNode*> qnode;
    qnode.push(root);
    qnode.push(NULL);

    std::vector<int> level;

    while(!qnode.empty())
    {
        TreeNode* tmp = qnode.front();
        qnode.pop();

        if(tmp != NULL)
        {
            level.push_back(tmp->val);

            if(tmp->left != NULL)
                qnode.push(tmp->left);
            if(tmp->right != NULL)
                qnode.push(tmp->right);
        }
        else
        {
            res.push_back(level);
            if(!qnode.empty())
            {
                qnode.push(NULL);
                level.clear();
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

    std::vector<std::vector<int> > res = levelOrder(root);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

