#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <math.h>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//int solver(TreeNode* root)
//{
//   if(root == NULL)
//       return 0;

//   int left = solver(root->left);
//   if(left == (-1))
//       return -1;

//   int right = solver(root->right);
//   if(right == (-1))
//       return -1;

//   if(std::abs(left - right) > 1)
//       return -1;

//   return std::max(left, right) + 1;
//}

//bool isBalanced(TreeNode* root)
//{
//    return solver(root) == (-1) ? 0 : 1;
//}


int solver(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int left = solver(root->left);
    int right = solver(root->right);

    if(left < 0 || right < 0)
        return -1;

    if(std::abs(left - right) > 1)
        return -1;

    return std::max(left, right) + 1;
}


bool isBalanced(TreeNode* root)
{
    return solver(root) >= 0;
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

    std::cout<<isBalanced(root)<<std::endl;

    system("pause");
    return 0;
}

