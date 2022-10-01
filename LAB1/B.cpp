#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector <int> v;
    vector <int> v2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
                if(v[i] >= v[j]){
                v2.push_back(v[j]);
                break;
            } else if(v[i] < v[j]){
                v2.push_back(-1);

            }
        }
    }
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    return 0;
}