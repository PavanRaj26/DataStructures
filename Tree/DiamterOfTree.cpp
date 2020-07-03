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
    private:
    int ans = 0;
public:
    int recur(TreeNode * root) {
        if (root == NULL) return 0;
        int lh = recur(root->left);
        int rh = recur(root->right);
        ans = max(ans,lh + rh);
        return max(lh,rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        recur(root);
        return ans;
    }
};
