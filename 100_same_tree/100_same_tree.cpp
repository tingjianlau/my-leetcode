/*************************************************************************
	> File Name: 100_same_tree.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/15
 ************************************************************************/

#include <iostream>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 栈
    bool isSameTree_0(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        
        stk1.push(p);
        stk2.push(q);
        
        while(!stk1.empty() && !stk2.empty()){
            TreeNode* tmp1 = stk1.top();
            TreeNode* tmp2 = stk2.top();
            stk1.pop();
            stk2.pop();
            
            if(tmp1 && tmp2){
                if(tmp1->val != tmp2->val)
                    return false;
                stk1.push(tmp1->left);
                stk1.push(tmp1->right);
                stk2.push(tmp2->left);
                stk2.push(tmp2->right);
            }
            if((tmp1 && !tmp2) || (!tmp1 && tmp2))
                return false;
        }

        return stk1.empty() == stk2.empty();
    }

    // 递归的方法
    bool isSameTree_1(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL) return p == q;

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};



