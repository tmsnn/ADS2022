#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long prime = 31;

long long getHash(string &s) {
    long long hash = 0;
    long long cur_prime = 1;
    for (int i = 0; i < s.size(); i++){
        long long curHash = (s[i] - 'a' + 1) * cur_prime % MOD;
        hash = (hash + curHash) % MOD;
        cur_prime = (cur_prime * prime) % MOD;
    }
    return hash;
}

vector <long long> getPrefixHashes(string &s) {
    vector<long long> hashes(s.size());
    long long cur_prime = 1;
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * cur_prime % MOD;
        if (i) hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        cur_prime = (cur_prime * prime) % MOD;
    }
    return hashes;
}

void rk(string & s, pair <string, int> &t, int &mx) {
    if(t.first.size() > s.size()) return;
    long long podHash = getHash(t.first);
    vector <long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.first.size() + 1; i ++){
        long long diff = hashes[i + t.first.size() - 1];
        if(i) diff -= hashes[i - 1];
        if (diff < 0) diff += MOD;
        if (i) podHash = (podHash * prime) % MOD;
        if (podHash == diff){
            t.second++;
            mx = max(mx, t.second);
        }
    }
}

int main(){
    while(true){
        int q; cin >> q;
        if(q == 0) break;
        pair<string, int> subs[q];
        for(int i = 0; i < q; i++){
            cin >> subs[i].first;
            subs[i].second = 0;
        }
        string s; cin >> s;
        int mx = -1;
        for(int i = 0; i < q; i++){
            rk(s, subs[i], mx);
        }
        cout << mx << endl;
        for(int i = 0; i < q; i++){
            if(subs[i].second == mx){
                cout << subs[i].first << endl;
            }
        }
    }
}