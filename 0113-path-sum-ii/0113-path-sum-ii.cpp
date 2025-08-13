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

    void dfs(TreeNode*node, int sum,vector<int>& path, vector<vector<int>>&ans){
       if(!node) return;

       path.push_back(node->val);
       if(!node->left && !node->right && node->val == sum){
        ans.push_back(path);
       }else{
        int rem = sum - node->val;
        dfs(node->left, rem, path, ans);
        dfs(node->right, rem, path, ans);
       }

       path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);

        return ans;
    }
};