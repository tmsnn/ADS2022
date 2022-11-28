#include <bits/stdc++.h> 
using namespace std; 
 
class Bst { 
private: 
    vector<int> level; 
    struct Node { 
        Node(int x) { 
            val = x; 
        } 
        int val; 
        Node *left = nullptr; 
        Node *right = nullptr; 
    }; 
 
    Node *root = new Node(1); 
    void push(Node *node, int x, int y, int z) { 
        if(!node){
            return;
        } 
        else if(node->val == x) { 
            if(z) { 
                node->right = new Node(y); 
            } 
            else { 
                node->left = new Node(y); 
            } 
            return; 
        } 
        push(node->right, x, y, z); 
        push(node->left, x, y, z); 
    } 

    int depth(Node *node) { 
        if(!node){ 
            return 0; 
        }
        return max(depth(node -> left), depth(node -> right)) + 1; 
    } 

    void dfs(Node *node, int x) { 
        if(!node){
            return;
        } 
        level[x]++; 
        dfs(node->right, x+1); 
        dfs(node->left, x+1); 
    } 
public: 
    void push(int x, int y, int z) { 
        push(root, x, y, z); 
    } 
    int width() { 
        level = vector <int> (depth(root)+1, 0); 
        dfs(root, 0); 
        return (*max_element(level.begin(), level.end())); 
    } 
}; 
 
int main() { 
    Bst tree; 
    int n; 
    cin >> n; 
    for(int i = 1 ; i < n; i++) { 
        int x, y, z; 
        cin >> x >> y >> z; 
        tree.push(x, y, z); 
    } 
    cout << tree.width(); 
    return 0; 
}