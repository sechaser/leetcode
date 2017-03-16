#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <stack>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//*******************Method 1**************************
//void solver(std::vector<int>& res, TreeNode* root)
//{
//    if(root != NULL)
//    {
//        solver(res, root->left);
//        res.push_back(root->val);
//        solver(res, root->right);
//    }
//}

//bool isValidBST(TreeNode* root)
//{
//    std::vector<int> res;
//    solver(res, root);

//    std::vector<int> temp = res;

//    std::vector<int>::iterator it = std::unique(temp.begin(), temp.end());
//    temp.erase(it, temp.end());
//    std::sort(temp.begin(), temp.end());

//    return res == temp;
//}



//Method 3
bool isValidBST(TreeNode *root, TreeNode* minNode, TreeNode* maxNode)
{
    if(!root)
        return true;

    if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val));
        return false;

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

bool isValidBST(TreeNode* root)
{
    return isValidBST(root, NULL, NULL);
}


int main()
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 2;
    node->left = NULL;
    node->right = NULL;
    TreeNode* root = node;

    node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 1;
    node->left = NULL;
    node->right = NULL;
    root->left = node;

    node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 3;
    node->left = NULL;
    node->right = NULL;
    root->right = node;

    std::cout<<isValidBST(root)<<std::endl;

    system("pause");
    return 0;
}

