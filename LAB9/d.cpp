#include <bits/stdc++.h>
using namespace std;

vector <int> prefixFunction(string s) {
    vector <int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }
    return pi;
}

int main(){
    string s; cin >> s;
    int n; cin >> n;
    string t;
    vector <string> v;
    int mx = 1;
    while(n--){
        cin >> t;
        t[0] = tolower(t[0]);
        vector <int> res = prefixFunction(t + '#' + s);
        t[0] = toupper(t[0]);
        int k = res[res.size() - 1];
        if(k > mx){
            mx = k;
            v.clear();
            v.push_back(t);
        } else if(k == mx){
            v.push_back(t); // 
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}