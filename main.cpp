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

std::vector<int> rightSideView(TreeNode* root)
{
    std::vector<int> res;
    if(root == NULL)
        return res;

    std::queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    std::vector<int> level;
    while(!q.empty())
    {
        TreeNode* p = q.front();
        q.pop();

        if(p)
        {
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            level.push_back(p->val);
        }
        else
        {
            res.push_back(level[level.size()-1]);
            if(!q.empty())
            {
                level.clear();
                q.push(NULL);
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

    root->right->left = node;

    std::vector<int> res = rightSideView(root);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

