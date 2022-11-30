#include <iostream>
#include <vector>
using namespace std;

vector <int> prefFunc(string s) {
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

vector<int> kmp(string s, string t){
    s = t + '#' + s + s;
    vector <int> ans;
    vector <int> pi = prefFunc(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size()) {
            ans.push_back(i - 2 * t.size());
        }
    }
    return ans;
}

int main(){
    string s, s1;
    cin >> s >> s1;
    vector <int> ans = kmp(s1, s);
    if(ans.empty()) {
        cout << -1;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}