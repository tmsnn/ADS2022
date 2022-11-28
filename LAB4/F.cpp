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
        if(node->val > x) { 
            if (node->left) {
                push(node->left, x); 
            } else {
                node->left = new Node(x); 
            }
        } else { 
            if(node->right) {
                push(node -> right, x); 
            } else {
                node -> right = new Node(x); 
            }
        } 
    } 

    int minTriangle(Node *node) { 
        if(!node){
            return 0; 
        }
        return (node && node -> left && node->right) + minTriangle(node -> left) + minTriangle(node -> right); 
    } 
 
public: 
    void push(int x) { 
        if(!root){ 
            root = new Node(x); 
        } else {
            push(root, x); 
        }
    } 
    int minTriangle() { 
        return minTriangle(root); 
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
    cout << tree.minTriangle(); 
    return 0; 
}