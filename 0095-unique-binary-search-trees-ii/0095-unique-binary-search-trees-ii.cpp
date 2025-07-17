class Solution {
public:
    vector<TreeNode*> generate(int low, int high) {
        vector<TreeNode*> result;
        if (low > high) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = low; i <= high; i++) {
            vector<TreeNode*> leftTrees = generate(low, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, high);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};
