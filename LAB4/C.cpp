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
            if (node->left) 
                push(node->left, x); 
            else 
                node->left = new Node(x); 
        } else { 
            if(node->right) 
                push(node->right, x); 
            else 
                node->right = new Node(x); 
        } 
    } 
 
    void print(Node *node, int x, bool used) { 
        if(!node) {
            return ; 
        }
        if(node->val == x){ 
            used = true; 
        }
        if(used){
            cout << node->val << " "; 
        }
        print(node->left, x, used); 
        print(node->right, x, used); 
    } 
 
public: 
 
    void push(int x) { 
        if(!root){ 
            root = new Node(x); 
        } else {
            push(root, x); 
        }
    } 
    void print(int x) { 
        print(root, x, false); 
    } 
}; 
 
int main() { 
    Bst tree; 
    int n, x; cin >> n; 
    for(int i = 0 ; i < n; i++) { 
        cin >> x; 
        tree.push(x); 
    }
    int m; cin >> m; 
    tree.print(m); 
    return 0; 
}