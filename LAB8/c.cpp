#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long num = 31;

long long getHash(string &s){
    long long hash = 0;
    long long cur_num = 1;
    for(int i = 0; i < s.size(); i++){
        long long curHash = (s[i] - 'a' + 1) * cur_num % MOD;
        hash = (hash + curHash) % MOD;
        cur_num = (cur_num * num) % MOD;
    }
    return hash;
}

vector <long long> getPrefixHashes(string &s){
    // vector <long long> hashes(s.size());
    long long cur_num = 1;
    vector <long long> hashes(s.size());
    for(int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * cur_num % MOD;
        if(i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        cur_num = (cur_num * num) % MOD;
    }
    return hashes;
}

int rk(string &s, string &t, vector <long long> &hashes, bool check[]){
    int res = 0;
    long long podHash = getHash(t);
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        long long diff = hashes[i + t.size() - 1];

        if(i) diff -= hashes[i - 1];
        if(diff < 0) diff += MOD; 
        if(i) podHash = (podHash * num) % MOD;
        if(podHash == diff){
            for(int j = i; j < i + t.size(); j++){
                check[j] = true;
            }
        }
    }
    return res;
}

int main(){
    string s; cin >> s;
    vector <long long> hashes = getPrefixHashes(s);
    bool check[s.size()];
    for(int i = 0; i < s.size(); i++){
        check[i] = false;
    }
    int q; 
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        rk(s, str, hashes, check);
    }
    for(int i = 0; i < s.size(); i++){
        if(!check[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}