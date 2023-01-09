#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    int m;
    vector <int> v;
    for(int i = 0; i < n; i++){
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while(l < n && r >= 0){
        if(v[l] + v[r] == x){
            cout << v[l] << " " << v[r];
            return 0;
        }
        else if(v[l] + v[r] > x){
            --r;
        } else {
            ++l;
        }
    }
}