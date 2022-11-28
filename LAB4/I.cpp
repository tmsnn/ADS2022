#include <iostream>
using namespace std;

struct Node {
  int val;
  int cnt;
  Node* left;
  Node* right;
  Node (int v) {
    this -> val = v;
    this -> cnt = 1;
    this -> left = nullptr;
    this -> right = nullptr;
  }
};

class BST {
  Node* root;
public:
  BST() { root = nullptr; }
  
  Node* push(int v, Node* cur) {
    if (!cur) return new Node(v);
    if (v < cur -> val) cur -> left = push(v, cur -> left);
    if (v > cur -> val) cur -> right = push(v, cur -> right);
    return cur;
  }

  void push(int v) {
    root = push(v, root);
  }

  void find(int v, Node* cur, Node* &target) {
    if (cur and !target) {
      if (cur -> val == v) target = cur;
      if (cur -> val < v) find(v, cur -> right, target);
      if (cur -> val > v) find(v, cur -> left, target);
    }    
  }

  void insert(int v) {
    Node* target = nullptr;
    find(v, root, target);
    if (target) ++(target -> cnt);
    else {
      root = push(v, root);
    }
  }

  // void preOrder(Node* cur) {
  //   if (cur) {
  //     preOrder(cur -> left);
  //     cout << cur -> val << " ";
  //     preOrder(cur -> right);
  //   }
  // }
  // void preOrder() {
  //   preOrder(root);
  // }

  void print_cnt(int v) {
    Node* target = nullptr;
    find(v, root, target);
    if (target) cout << target -> cnt << endl;
    else cout << 0 << endl;
  }

  // void find_parent(int v, Node* cur, Node* &parent, Node* &del) {
  //   if ((cur -> left or cur -> right) and !parent) {
  //     if (cur -> left and cur -> left -> val == v) {
  //       parent = cur;
  //       del = cur -> left;
  //       return;
  //     }
  //     if (cur -> right and cur -> right -> val == v) {
  //       parent = cur;
  //       del = cur -> right;
  //       return;
  //     }
  //     if (cur -> val < v) find_parent(v, cur -> right, parent, del);
  //     if (cur -> val > v) find_parent(v, cur -> left, parent, del);
  //   }
  // }

  // void find_rightest (Node* &cur, Node* &parent_of_rightest) {
  //   while (cur -> right) {
  //     parent_of_rightest = cur;
  //     cur = cur -> right;
  //   }
    
  // }

  void pop (int v) {
    Node* target = nullptr;
    find(v, root, target);
    --(target -> cnt);
    // del is root
    // if (v == root -> val) {  
    //   // root has no child
    //   if (root -> left == nullptr and root -> right == nullptr) {
    //     root = nullptr;
    //   }
    //   // root has one child
    //   else if (root -> left and root -> right == nullptr or root -> left == nullptr and root -> right) {
    //     if (root -> left) { // root has left child
    //       root = root -> left;
    //     }
    //     else { // root has right child
    //       root = root -> right;
    //     }
    //   }

    //   // root has both children
    //   else {
    //     Node* rightest = root -> left;
    //     Node* parent_of_rightest = root -> left;
    //     find_rightest(rightest, parent_of_rightest);
    //     int v = rightest -> val;
    //     parent_of_rightest -> right = rightest -> left;

    //   }
    // }
    // else {
    //   Node* parent = nullptr;
    //   Node* del = nullptr;
    //   find_parent(v, root, parent, del);
      
    //   // del has no child
    //   if(!(del -> left) and !(del -> right)) {
    //     if (parent -> left and parent -> left == del) { // del is left child
    //         parent -> left = nullptr;
    //     }
    //     else { // del is right child
    //       parent -> right = nullptr;
    //     }
    //   }

    //   // del has one child
    //   else if (del -> left and !(del -> right) or !(del -> left) and del -> right) {
    //     if (del -> left) {  // has left child 
    //         parent -> left = nullptr;
    //     }
    //     else {              // has right child
    //       parent -> right = nullptr;
    //     }
    //   }

    //   // del has both children 
    //   else {

    //   }

    // }
  }
  
};

int main() {

  int n;
  cin >> n;
  BST tree;

  for (int i = 0; i < n; ++i) {
    string s; int x;
    cin >> s >> x;
    if (s == "insert") tree.insert(x);
    else if (s == "cnt") tree.print_cnt(x);
    // else if (s == "p") tree.preOrder();
    else tree.pop(x);
    
  }

}