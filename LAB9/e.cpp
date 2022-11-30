#include <bits/stdc++.h>
using namespace std;

vector <int> preFunc(string s) {
    vector<int> pi(s.size());
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

int main() {
    int t; cin >> t;
    string s; int k;
    while (t--){
        cin >> s >> k;
        vector <int> ans = preFunc(s);
        int fullstring = (s.size() - ans[ans.size() - 1]) * k + ans[ans.size() - 1];
        cout << fullstring << endl;
    }
}
// узнать есть ли суффикс равный префиксу и к размеру строки прибавить (s.size() - suff.size()) * (k - 1)
    // cout << "size: " << s.size();