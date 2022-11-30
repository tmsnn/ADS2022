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
    vector <int> ans = prefixFunction(s);
    // vector <int> v;
    // int t = 0;
    int cnt = 0;
    // t = ans.size() - ans[ans.size() - 1];  //period
    for(int i = 0; i < ans.size() - 1; i++) {
        int t = 0;
        // t = ans.size() - ans[ans.size() - 1];
        t = i + 1 - ans[i];
        if(ans[i] % t == 0 && ((i + 1) / t) % 2 == 0){
            cnt++;
        }
    }
    cout << cnt;
}