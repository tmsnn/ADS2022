#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 9;
long long prime = 31;


long long getHash(string & s) {
    long long hash = 0;
    long long cur_prime = 1;
    for (int i = 0; i < s.size(); i ++){
        long long curHash = (s[i] - 'a' + 1) * cur_prime % MOD;
        hash = (hash + curHash) % MOD;
        cur_prime = (cur_prime * prime) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string &s) {
    long long cur_prime = 1;
    vector<long long> hashes(s.size());
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * cur_prime % MOD;
        if (i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        cur_prime = (cur_prime * prime) % MOD;
    }
    return hashes;
}

int rk(string &s, string &t, vector<long long> &hashes) {
    int res = 0;
    long long smallHash = getHash(t);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += MOD;
        if (i) smallHash = (smallHash * prime) % MOD;
        if (smallHash == hashDiff){
            res++;
        }
    }
    return res;
}


int main() {
    string s;
    cin >> s;
    vector<long long> hashes = getPrefixHashes(s);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        string t = "";
        // for (int i = l; i < r; i ++){
        //     str += s[i];
        // }
        t = s.substr(l, r - l);
//        cout << str << endl;
        cout << rk(s, t, hashes) << endl;
    }
}