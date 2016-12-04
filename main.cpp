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


//*******************************************Method 1**************************************
//void preorder(TreeNode* root, std::vector<TreeNode*>& nodeVec)
//{
//    if(root != NULL)
//    {
//        nodeVec.push_back(root);
//        preorder(root->left, nodeVec);
//        preorder(root->right, nodeVec);
//    }
//}

//void flatten(TreeNode* root)
//{
//    if(root == NULL)
//        return;

//    std::vector<TreeNode*> nodeVec;
//    preorder(root, nodeVec);

//    size_t sz = nodeVec.size();
//    for(std::vector<TreeNode*>::size_type i = 0; i != sz - 1; ++ i)
//    {
//        nodeVec[i]->left  = NULL;
//        nodeVec[i]->right = nodeVec[i+1];
//    }
//    nodeVec[sz-1]->left  = NULL;
//    nodeVec[sz-1]->right = NULL;
//}



//*****************************************Method 2********************************************
//void flatten(TreeNode* root)
//{
//    if(root == NULL)
//        return ;

//    if(root->left != NULL)
//        flatten(root->left);

//    if(root->right != NULL)
//        flatten(root->right);

//    TreeNode* tmp = root->right;
//    root->right = root->left;
//    root->left = NULL;

//    while(root->right != NULL)
//        root = root->right;
//    root->right = tmp;
//}


//*****************************************Method 3*********************************************
void flatten(TreeNode *root)
{

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

