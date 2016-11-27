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

//*************************************************Method 1*************************************
//void solver(TreeNode* root, int tmp, int& res)
//{
//    if(root == NULL)
//    {
//        res = 0;
//        return;
//    }

//    ++ tmp;
//    //Leaf node
//    if(root->left == NULL && root->right == NULL)
//    {
//        res = std::min(tmp, res);
//        return;
//    }

//    if(root->left != NULL)
//        solver(root->left, tmp, res);

//    if(root->right != NULL)
//        solver(root->right, tmp, res);
//}

//int minDepth(TreeNode* root)
//{
//    int res = INT_MAX;
//    int tmp = 0;
//    solver(root, tmp, res);

//    return res;
//}



//**************************Method 2********************************
//int minDepth(TreeNode* root)
//{
//    if(root == NULL)
//        return 0;

//    if(root->left == NULL)
//        return minDepth(root->right) + 1;

//    if(root->right == NULL)
//        return minDepth(root->left) + 1;

//    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
//}



//****************************Method 3********************************
int minDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;

    int level = 1;
    std::queue<TreeNode*> qnode;
    qnode.push(root);
    qnode.push(NULL);

    while(!qnode.empty())
    {
        TreeNode* tmp = qnode.front();
        qnode.pop();

        if(tmp != NULL)
        {
            if(tmp->left == NULL && tmp->right == NULL)
                return level;

            if(tmp->left)
                qnode.push(tmp->left);
            if(tmp->right)
                qnode.push(tmp->right);
        }
        else
        {
            ++ level;
            if(!qnode.empty())
                qnode.push(NULL);
        }
    }

    return level;
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

    std::cout<<minDepth(root)<<std::endl;


    system("pause");
    return 0;
}

