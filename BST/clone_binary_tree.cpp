/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    private:
    unordered_map<Node *,NodeCopy *> mp;
public:
    NodeCopy *newNode(int val) {
        NodeCopy *nn = new NodeCopy();
        nn->left = NULL;
        nn->right = NULL;
        nn->val = val;
        nn->random = NULL;
        return nn;
    }
    void assign(Node *root) {
        if (root == NULL) {
            return ;            
        }
        NodeCopy *nn = newNode(root->val);
        mp[root] = nn;
        assign(root->left);
        assign(root->right);
        return ;
    }
    void recur(Node *root) {
        if (root == NULL) {
            return ;            
        }
        recur(root->left);
        recur(root->right);
        if (root->left != NULL) 
            mp[root]->left = mp[root->left];
        if (root->right != NULL)            
            mp[root]->right = mp[root->right];
        if (root->random) 
            mp[root]->random = mp[root->random];
        
        return ;
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root == NULL) return NULL; 
        assign(root);
        recur(root);
        return mp[root];
    }
};
