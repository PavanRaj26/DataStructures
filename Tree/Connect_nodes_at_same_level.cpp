/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    private:
    queue<Node *> Q;
public:
    Node* connect(Node* root) {
        
        if (root == NULL) return NULL;
        Q.push(root);
        while(!Q.empty()) {
            int sz = Q.size();
            Node *prev = NULL;
            while(sz--) {
                Node *cur = Q.front();
                Q.pop();
                if (prev) 
                    prev->next = cur;
                prev = cur;
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);            
            }
            if(prev)
                prev->next = NULL;            
        }
        return root;
    }
};
