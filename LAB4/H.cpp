#include <iostream>
#include <vector>
using namespace std;
vector<bool> u(1e9+3, 0);
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

  void solve(Node* cur) {
    if (cur) {
      solve(cur -> right);
      res += cur -> val;
      cout << res << " ";
      solve(cur -> left);
    }
  }

  void solve() {
    solve(root);
  }
  
};

int main() {

  int n;
  cin >> n;
  BST tree;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    tree.push(x);
  }
  tree.solve();

}