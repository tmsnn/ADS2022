#include <bits/stdc++.h>
using namespace std;

string int_to_bin(long long d){
    string s; 
    while(d > 0){
        if(d % 2){
            s += '1';
        } else {
            s += '0';
        }
        d /= 2;
    }
    return s;
}

int main(){
    int n; cin >> n;
    // stack <char> st;
    for(int i = 0; i < n; ++i){
        long long d; cin >> d;
        bool ok = true;
        deque <char> st;
        string s = int_to_bin(d);
        //скобочная последовательность 
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == '0'){
                st.push_back('0');
            } else {
                if(st.empty()){
                    ok = false;
                }
                else st.pop_back();
            }
        }
        // while(!st.empty()){
        //     cout << st.top() << " ";
        //     st.pop_back();
        // }
        if(ok && st.empty()){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
