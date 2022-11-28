#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;

    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct Bst{
    Node * root;
    Bst(){
        root = nullptr;
    }

    private:
     Node *  push(Node * cur, int val){
        if(cur == nullptr){
            return new Node(val);
        } 
        else if(cur->val  < val){
            cur->right = push(cur->right, val);
        }
        else if(cur->val > val){
            cur->left = push(cur->left , val);
        }
        return cur;
     }
     void _check(string s){
         Node * cur = root;
         for(int i = 0; i < s.size(); i++){
            if(s[i]=='L'){
                cur = cur->left;
            }
            else if(s[i] == 'R'){
                cur = cur->right;
            }
            if(cur == nullptr){
                cout<<"NO"<<endl;
                return;
            }

        }
      cout << "YES" << endl;

     }
    public :
     void push(int val){
        Node * newNode = push(this->root, val);
       
       if(root == nullptr){
           root = newNode;
        }
    }

    void check( string s){
        _check(s);

    }
};
int main(){
   Bst tree;
    int n,m, x;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin>>x;
        tree.push(x);
    }
    while(m--){
        string s;
        cin>>s;
        tree.check(s);
    }
}