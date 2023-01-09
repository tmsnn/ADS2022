#include <iostream>
#include <vector>
using namespace std;
int g[150][150];
bool used[150][150];
int n, m;

void dfs(int i, int j) {
  if (i < 0 or j < 0 or i >= n or j >= m) return;
  if (used[i][j] == 1 or g[i][j] == 0) return;
  used[i][j] = 1;

  dfs (i + 1, j);
  dfs (i - 1, j);
  dfs (i, j + 1);
  dfs (i, j - 1);
}

int main() {

  cin >> n >> m;
  char c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      if (c == '1') g[i][j] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[i][j] and g[i][j] == 1) {
        dfs(i, j);
        ++ans;
      }
    }
  }

  cout << ans << endl;

}