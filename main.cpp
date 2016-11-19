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


//*************************Method 2****************************
bool isValidBST(TreeNode* root)
{
    std::stack<TreeNode*> S;
    TreeNode* pre = NULL, *p = root;

    while(p || !S.empty())
    {
        while(p)
        {
            S.push(p);
            p = p->left;
        }

        if(!S.empty())
        {
            p = S.top();
            S.pop();

            if(pre && p->val <= pre->val)
                return false;
            pre = p;
            p = p->right;
        }
    }

    return true;
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

