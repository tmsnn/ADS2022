#include <bits/stdc++.h> 
using namespace std; 
 
class Bst { 
private: 
    struct Node{ 
        Node(int x) { 
            val = x; 
        } 
        int val; 
        Node *left = nullptr; 
        Node *right = nullptr; 
    }; 

    Node *root = nullptr; 
    void push(Node *node, int x) { 
        if(node -> val > x) { 
            if (node->left) {
                push(node->left, x); 
            } else {
                node->left = new Node(x); 
            }
        } else { 
            if(node->right) {
                push(node->right, x); 
            } else {
                node->right = new Node(x); 
            }
        } 
    } 
 
    int sizeOfNode(Node *node, int x, bool used) { 
        if(!node) 
            return 0; 
        if(node->val == x) 
            used = true; 
        return used + sizeOfNode(node->right, x, used) + sizeOfNode(node->left, x, used); 
    } 
 
public: 
    void push(int x) { 
        if(!root) {
            root = new Node(x); 
        } else {
            push(root, x);
        } 
    } 
    int sizeOfNode(int x) { 
        return sizeOfNode(root, x, false); 
    } 
}; 
 
int main() { 
    Bst tree; 
    int n; 
    cin >> n; 
    for(int i = 0 ; i < n; i++) { 
        int x; 
        cin >> x; 
        tree.push(x); 
    } 
    int x; 
    cin >> x; 
    cout << tree.sizeOfNode(x); 
    return 0; 
}