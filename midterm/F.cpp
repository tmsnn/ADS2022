#include <bits/stdc++.h>
using namespace std;

int sum = 0;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
        this -> left = this -> right = nullptr;
    }
};

class BST{
    Node* root;
public:
    BST(){
        root = nullptr;
    }

    Node* add(int val, Node* cur, int level){
        if(!cur){
            sum += val - level;
            return new Node(val);
        }
        if(cur -> val < val){
            cur -> right = add(val, cur -> right, level + 1);
        }
        if(cur -> val > val){
            cur -> left = add(val, cur -> left, level + 1);
        }
        return cur;
    }
    void add(int val){
        root = add(val, root, 0);
    }
    void inOrder(Node* cur){
        if(cur) {
            if(!(cur -> right) && !(cur -> left)){
                sum++;
            }
        }
    }
    void onOrder(){
        inOrder(root);
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.add(x);
    }
    cout << sum << endl;
}