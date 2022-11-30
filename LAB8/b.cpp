#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 9;
long long prime = 31;

map <int, int> mp;
int res;

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

vector <long long> getPrefixHashes(string & s) {
    vector <long long> hashes(s.size());
    long long cur_prime = 1;
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * cur_prime % MOD;
        if (i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        cur_prime = (cur_prime * prime) % MOD;
    }
    return hashes;
}

void rk(string & s, string & t) {
    if (t.size() > s.size()) return;
    long long podHash = getHash(t);
    vector <long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += MOD;
        if (i) podHash = (podHash * prime) % MOD;
        if (podHash == hashDiff){
            if (mp.find(i) != mp.end()){
                res++;
            }
            mp[i] = 1;
        }
    }
}

int main() {
    string student1, student2, parasite;
    cin >> student1 >> student2 >> parasite;
    // map <int, int> mp;
    // int res;
    rk(student1, parasite);
    rk(student2, parasite);
    cout << res << endl;
}