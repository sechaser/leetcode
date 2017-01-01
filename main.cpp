#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, std::vector<int>& res)
{
    if(root == NULL)
        return 0;

    int left  = helper(root->left, res);
    int right = helper(root->right, res);
    int cur   = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);

    if(cur > res[0])
        res[0] = cur;

    return root->val + std::max(left, std::max(right, 0));
}

int maxPathSum(TreeNode* root)
{
    if(root == NULL)
        return 0;

    std::vector<int> res;
    res.push_back(INT_MIN);

    helper(root, res);

    return res[0];
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

    std::cout<<maxPathSum(root)<<std::endl;

    system("pause");
    return 0;
}

