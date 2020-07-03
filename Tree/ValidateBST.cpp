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
    bool recur(TreeNode *root,long long int mn,long long int mx)  {
        if (root == NULL) return true;
        if (root->val > mx || root->val < mn) return false;
        long long int lft = root->val * 1ll - 1;
        long long int rt = root->val * 1ll + 1;
        if (recur(root->left,mn,lft) && recur(root->right,rt,mx))
            return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
            return recur(root,LLONG_MIN,LLONG_MAX);        
    }
};
