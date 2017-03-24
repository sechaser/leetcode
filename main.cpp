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

//bool hasPathSum(TreeNode* root, int sum)
//{
//    if(root == NULL)
//        return false;

//    if(root->left == NULL && root->right == NULL && root->val == sum)
//        return true;

//    return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
//}


bool solver(TreeNode* root, int pathSum, int& sum)
{
    pathSum += root->val;

    std::cout<<root->val<<std::endl;
    if(!root->left && !root->right)
    {
        if(sum == pathSum)
            return true;
    }

    if(root->left && solver(root->left, pathSum, sum))
        return true;

    if(root->right && solver(root->right, pathSum, sum))
        return true;

    return false;
}

bool hasPathSum(TreeNode* root, int sum)
{
    if(!root)
        return false;

    int pathSum = 0;
    return solver(root, pathSum, sum);
}



int main()
{
    TreeNode* node = new TreeNode(1);
    TreeNode* root = node;

    node = new TreeNode(2);
    root->left = node;

    node = new TreeNode(3);
    root->right = node;


    node = new TreeNode(4);
    root->left->left = node;

    node = new TreeNode(5);
    root->left->right = node;

    std::cout<<hasPathSum(root, 7)<<std::endl;


    system("pause");
    return 0;
}

