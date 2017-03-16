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


//***********************************************Method 1********************************************
void solver(TreeNode* root, int& maxDep, int curDep)
{
    ++ curDep;
    if(!root->left && !root->right)
    {
        maxDep = std::max(maxDep, curDep);
        return;
    }

    if(root->left)
        solver(root->left, maxDep, curDep);

    if(root->right)
        solver(root->right, maxDep, curDep);
}

int maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int maxDep = INT_MIN, curDep = 0;
    solver(root, maxDep, curDep);

    return maxDep;
}



//***********************************************Method 2**********************************************
//int maxDepth(TreeNode *root)
//{
//    if(root == NULL)
//        return 0;

//    int res = 0;
//    std::queue<TreeNode*> qnode;
//    qnode.push(root);
//    qnode.push(NULL);

//    while(!qnode.empty())
//    {
//        TreeNode* tmp = qnode.front();
//        qnode.pop();

//        if(tmp != NULL)
//        {
//            if(tmp->left)
//                qnode.push(tmp->left);
//            if(tmp->right)
//                qnode.push(tmp->right);
//        }
//        else
//        {
//            ++ res;
//            if(!qnode.empty())
//                qnode.push(NULL);
//        }
//    }

//    return res;
//}


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

    std::cout<<maxDepth(root)<<std::endl;

    system("pause");
    return 0;
}

