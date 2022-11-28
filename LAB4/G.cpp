#include <iostream>
#include <vector>
using namespace std;
vector <bool> u(1e9+3, 0);
int res = 0;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node (int v) {
    this -> val = v;
    this -> left = nullptr;
    this -> right = nullptr;
  }
};

class BST {
  Node* root;
public:
  BST() {
    root = nullptr; 
  }
  
  Node* push(int v, Node* cur) {
    if (!cur) return new Node(v);
    if (v < cur -> val) cur -> left = push(v, cur -> left);
    if (v > cur -> val) cur -> right = push(v, cur -> right);
    return cur;
  }

  void push(int v) {
    root = push(v, root);
  }

  int height(Node* cur) {
    if (!cur) return 0;
    return max(height(cur->left), height(cur->right)) + 1;
  }

  void inOrder(Node* cur) {
    if (cur) {
      if (cur -> left and cur -> right) {
        res = max(res, height(cur->left) + height(cur -> right) + 1);
      }
      inOrder(cur -> left);
      inOrder(cur -> right);
    }
  }

  void solve() {
    res = height(root);
    inOrder(root);
    cout << res << endl;
  }
  
};

int main() {
  int n;
  cin >> n;
  BST tree;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (!u[x]) tree.push(x);
    u[x] = 1;
  }
  tree.solve();
}