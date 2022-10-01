#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> st;
    string s;
    int i = 0;
    int a;
    while(s[i] != '!'){
        cin >> s;
        // while(true){
            if(s[0] == '+'){
                int x; cin >> x;
                st.push_front(x);
            }
            else if(s[0] == '-'){
                int x; cin >> x;
                st.push_back(x);
            }
            else if(s[0] == '*'){
                if(st.size() == 1){
                    cout << st.front() * 2 << endl;
                    st.pop_front();
                }
                else if(st.size() >= 2){
                    cout << st.front() + st.back() << endl;
                    st.pop_front();
                    st.pop_back();
                } else cout << "error" << endl;
            }
        } 
    return 0;
}
