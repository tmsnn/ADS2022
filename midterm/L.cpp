#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
struct Node{
    int val; 
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class Bst{
private:
    Node * root;

    Node* push(Node* cur, int val){
        if(cur == nullptr) return new Node(val);
        else if(cur -> val < val){
            cur -> right = push(cur -> right, val);
        } else if(cur -> val > val){
            cur -> left = push(cur -> left, val);
        }
        return cur;
    }

    void inOrder(Node* cur){
        if(cur != nullptr){
            inOrder(cur -> left);
        if(cur -> left == nullptr && cur -> right == nullptr){
            cnt++;
        }
        inOrder(cur -> right);
        }
    }
        
public:
    Bst(){
        root = nullptr;
    }
    void push(int val){
        root = push(root, val);
    }
    void inOrder(){
        inOrder(root);
    }
};

int main(){
    Bst tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    tree.inOrder();
    cout << cnt;
}