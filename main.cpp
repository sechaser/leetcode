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


//bool solver(TreeNode* lnode, TreeNode* rnode)
//{
//    if(lnode == NULL && rnode == NULL)
//        return true;

//    if(lnode == NULL || rnode == NULL)
//        return false;

//    if(lnode == rnode)
//        return solver(lnode->left, rnode->right);

//    if(lnode->val != rnode->val)
//        return false;

//    return solver(lnode->left, rnode->right) && solver(lnode->right, rnode->left);
//}

//bool isSymmetric(TreeNode* root)
//{
//    return solver(root, root);
//}


//bool isSymmetric(TreeNode* root)
//{
//    if(root == NULL)
//        return true;

//    std::queue<TreeNode*> ql, qr;
//    ql.push(root->left);
//    qr.push(root->right);

//    while(!ql.empty() && !qr.empty())
//    {
//        TreeNode* lnode = ql.front();
//        TreeNode* rnode = qr.front();

//        ql.pop();
//        qr.pop();

//        if(lnode == NULL && rnode == NULL)
//            continue;

//        if(lnode == NULL || rnode == NULL)
//            return false;
//        if(lnode->val != rnode->val)
//            return false;

//        ql.push(lnode->left);
//        ql.push(lnode->right);

//        qr.push(rnode->right);
//        qr.push(rnode->left);
//    }

//    if(!ql.empty() || !qr.empty())
//        return false;

//    return true;
//}

bool solver(TreeNode* ltree, TreeNode* rtree)
{
    if(!ltree && !rtree)
        return true;

    if(ltree && rtree && (ltree->val == rtree->val))
        return solver(ltree->left, rtree->right) && solver(ltree->right, rtree->left);

    return false;

}

bool isSymmetric(TreeNode* root)
{
    if(root == NULL)
        return false;

    return solver(root->left, root->right);
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
    node->val = 2;
    node->left = NULL;
    node->right = NULL;

    root->left = node;


    std::cout<<isSymmetric(root)<<std::endl;

    system("pause");
    return 0;
}

