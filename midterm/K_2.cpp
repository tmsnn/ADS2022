#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> d;
    int n, x, m; cin >> n;
    int cnt = 0;
    while(n--){
        cin >> x;
        if(x == 2){
            cnt++;
        }
        if(x == 1){
            if(cnt % 2 != 0){
                cin >> m;
                d.push_front(m);
            } else {
                cin >> m;
                d.push_back(m);
            }
        }
    }
    while(!d.empty()){
            if(cnt % 2 != 0){
                cout << d.back() << " ";
                d.pop_back();
            } else {
                cout << d.front() << " ";
                d.pop_front();
            }
        }
}