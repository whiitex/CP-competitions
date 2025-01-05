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
    int maxPathSum(TreeNode* root) {
        int ans = -1e8;
        auto dfs = [&ans] (auto f, TreeNode* root) -> int {
            ans = max(ans, root->val);
            int res = root->val, lx = 0, rx = 0;
            if (root->left != nullptr) lx = max(lx, f(f, root->left));
            if (root->right != nullptr) rx = max(rx, f(f, root->right));
            ans = max(ans, lx + rx + res);
            res = max(lx + res, rx + res);
            return max(0, res);
        };

        dfs(dfs, root);
        return ans;
    }
};