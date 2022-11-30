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
    string s, t;
    cin >> s >> t;
    vector <int> v = prefixFunction(s);
    string s1 = " ";
    bool flag = false;
    for(int i = 0; i < t.size() / s.size(); i++){
        s1 += s;
    }
    if(t.size() % s.size() != 0) s1 += s;

    vector <int> res = prefixFunction(t + '#' + s1);
    for(int i = 0; i < res.size(); i++){
        if(t.size() == res[i]){
            flag = true;
        }
    }

    if(flag) {
        if(t.size() % s.size()){
            cout << t.size() / s.size() + 1;
        } else cout << t.size() / s.size();
    } else {
        vector <int> v = prefixFunction(t + '#' + s1 + s);
        for(int i = 0; i < v.size(); i++){
            if(t.size() == v[i]) flag = true;
        } 
        if(flag) {
            if(t.size() % s.size()){
                cout << t.size() / s.size() + 1 + 1;
            } else {
                cout << t.size() / s.size() + 1;
            }
        } else {
            cout << -1;
        }
    }
}