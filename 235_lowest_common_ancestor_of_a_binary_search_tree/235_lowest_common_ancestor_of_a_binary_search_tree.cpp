/*************************************************************************
	> File Name: 235_lowest_common_ancestor_of_a_binary_search_tree.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

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
    // 注意题中的二叉树是搜索二叉树(BST)，任意一个节点的左孩子小于右孩子
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((root->val - p->val) * (root->val - q->val) > 0){ // 如果所求两个节点同时大于或小于root，则说明在root的同一侧
            root = root->val > p->val ? root->left : root->right;
        }
        return root;
    }
};

