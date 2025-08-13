/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool check(TreeNode* root, int Sum){
        if(!root )return false;

        if(!root->left && !root->right){
            if(root->val == Sum) return true;
        }

        int rem = Sum - root->val;
        return (check(root->left, rem) || check(root->right, rem));

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum);
    }
};