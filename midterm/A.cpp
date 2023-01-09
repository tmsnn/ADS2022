#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node * left;
    node * right;
    node(int val){
        this -> val = val;
        right = nullptr;
        left = nullptr;
    }
};

int arr[100078], j = 0;
struct bst {
    node * root;

    bst(){
        root = nullptr;
    }

    node* insert(node* root, int val){
        if(root == nullptr) return new node(val);
        if(root -> val > val) root -> left = insert(root -> left, val);
        if(root -> val < val) root -> right = insert(root -> right, val);
        return root;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void inorder(node * root){
        if(root == nullptr) return;
        inorder(root -> left);
        cout << root -> val << endl;
        inorder(root -> right);
    }
    void postorder(node* root){
        if(root == nullptr) return;
        postorder(root -> right);
        cout << root -> val << " ";
        postorder(root -> left);
    }
    void inorder(){
        inorder(root);
        cout << endl;
    }
    void postorder(){
        postorder(root);
        cout << endl;
    }

    void triangle(node * cur){
        if(cur == nullptr) return;
        int L = toLeft(cur -> left);
        int R = toRight(cur -> right);
        int cnt = min(L, R);
        for(int i = 1; i <= cnt; i++){
            arr[i]++;
        }
        triangle(cur -> left);
        triangle(cur -> right);
    }
    int toLeft(node * cur){
        if(cur == nullptr) return 0;
        return toLeft(cur -> left) + 1;
    }
    int toRight(node * cur){
        if(cur == nullptr) return 0;
        return toRight(cur -> right) + 1;
    }
};
int main(){
    bst tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.insert(x);
    }
    tree.triangle(tree.root);
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}