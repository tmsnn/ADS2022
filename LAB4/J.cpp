#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;

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

  Node* build_perfect_bst(int v[], int l, int r) {
    if (l > r) return nullptr;
    int m = l + (r - l) / 2;
    Node* cur = new Node(v[m]);
    cout << cur -> val << " ";
    cur -> left = build_perfect_bst(v, l, m - 1);
    cur -> right = build_perfect_bst(v, m + 1, r);
    return cur;
  }

  void build_perfect_bst(int v[], int n) {
    root = build_perfect_bst(v, 0, n - 1);
  }

};

int main() {

  int n;
  cin >> n;
  BST tree;
  n = (1 << n) - 1;
  int v[n];

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v, v + n);
  tree.build_perfect_bst(v, n);
}