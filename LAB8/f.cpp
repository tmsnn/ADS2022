#include <bits/stdc++.h>
using namespace std;

long long MOD = 1011148561;
long long prime = 31;

int main() { 
    string s; cin >> s;
    vector <long long> powsOfprimes(s.size());
    powsOfprimes[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        powsOfprimes[i] = (powsOfprimes[i - 1] * prime) % MOD;
    }

    vector <long long> hashes (s.size() + 1);
    for (int i = 0; i < s.size(); i++){
        hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * powsOfprimes[i]) % MOD;
    }
    int cnt = 0;
    for (int i = 1; i <= s.size(); ++i){
        unordered_set <long long> ans;
        for (int j = 0; j <= s.size() - i; ++j) {
            long long hash = (hashes[j + i] + MOD - hashes[j]) % MOD;
            hash = (hash * powsOfprimes[s.size() - (j + 1)]) % MOD;
            ans.insert(hash);
        }
        cnt += ans.size();
    }
    cout << cnt << endl;
}