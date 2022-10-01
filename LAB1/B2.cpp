#include <bits/stdc++.h> 
using namespace std; 
int main() { 
    int n; cin >> n; 
    vector <int> v;
    queue <int> q; 
    for (int i = 0; i < n; i++){ 
       int x; cin >> x; 
       v.push_back(x);
    } 
    // reverse(v.begin(), v.end());
    for (int i = 0; i < n; i ++){ 
        if (i == 0){ 
            q.push(-1); 
            continue; 
        } 
        bool greater = false; 
        for (int j = i - 1; j >= 0; j--){ 
            if (v[j] <= v[i]){ 
                q.push(v[j]); 
                greater = true; 
                break; 
            } 
        } 
        if (!greater) q.push(-1); 
    } 
    while(!q.empty()){ 
        cout << q.front() << " "; 
        q.pop(); 
    } 
}