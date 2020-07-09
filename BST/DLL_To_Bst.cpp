/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    private:
    vector<int> v;
    
public:
    Node *newNode() {
        Node * nn = new Node();
        nn->next = NULL;
        nn->prev = NULL;        
        return nn;
    }
    Node *arrayToBst(vector<int> v,int st,int end) {
        if (st > end) return NULL;
        
        int mid = (st + end) / 2;
        Node* nn = newNode(v[mid]);
        nn->right = arrayToBst(v,mid+1,end);
        nn->left = arrayToBst(v,st,mid-1);
        return nn;
    }
    Node* flatten(Node* head) {
        
        Node *ptr = head;
        while(ptr != NULL) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(v.begin(),v.end());
        return arrayToBst(v,0,n);
    }
};
