#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

long long MOD = 1011148561;
long long X = 31;

int main() { 
  string s;
  cin >> s;
  vector<long long> p_pows(s.size());
  p_pows[0] = 1;
  for (int i = 1; i < s.size(); i++) {
    p_pows[i] = (p_pows[i - 1] * X) % MOD;
  }
  vector<long long> hashes (s.size()+1);
  

  
  for (int i = 0; i < s.size(); i++)
    hashes[i+1] = (hashes[i] + (s[i] - 'a' + 1) * p_pows[i]) % MOD;

  // for (int i = 0 ; i < hashes.size(); ++i) cout << hashes[i] << " ";
  int ans = 0;
  for (int i = 1; i <= s.size(); ++i) {
    unordered_set<long long> res;
    int k = 1;
    for (int j = 0; j <= s.size() - i; ++j) {
      long long hs = (hashes[j+i]+MOD- hashes[j]) % MOD;
      hs = (hs * p_pows[s.size()-(j+1)]) % MOD;
      res.insert(hs);
    }
    ans += res.size();
  }
  // cout << endl;
  cout << ans << endl;
}