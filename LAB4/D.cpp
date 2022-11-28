#include <bits/stdc++.h> 
using namespace std; 
 
class Bst { 
private: 
    map<int, int> levelSum; 
    struct Node{ 
        Node(int x) { 
            val = x; 
        } 
        int val; 
        Node *left = nullptr; 
        Node *right = nullptr; 
    }; 
    Node *root = nullptr; 
    void add(Node *node, int x) { 
        if(node->val > x) { 
            if (node->left) 
                add(node->left, x); 
            else 
                node->left = new Node(x); 
        } else { 
            if(node->right) 
                add(node->right, x); 
            else 
                node->right = new Node(x); 
        } 
    } 
    void getLevelsSum(Node *node, int level) { 
        if(!node) 
            return; 
        levelSum[level] += node->val; 
        getLevelsSum(node->right, level+1); 
        getLevelsSum(node->left, level+1); 
    } 
public: 
    void add(int x) { 
        if(!root) 
            root = new Node(x); 
        else 
            add(root, x); 
    } 
    vector<int> getLevelsSum() { 
        getLevelsSum(root, 0); 
        vector<int> res; 
        for(auto [key, val]: levelSum) 
            res.push_back(val); 
        return res; 
    } 
}; 
 
int main() { 
    Bst bst; 
    int n; 
    cin >> n; 
    for(int i = 0 ; i < n; i++) { 
        int x; 
        cin >> x; 
        bst.add(x); 
    } 
    vector<int> levels = bst.getLevelsSum(); 
    cout << levels.size() << endl; 
    for(int i = 0; i < levels.size(); i++) 
        cout << levels[i] << " ";  
    return 0; 
}