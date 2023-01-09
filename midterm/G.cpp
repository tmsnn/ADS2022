#include <bits/stdc++.h> 
using namespace std; 
 
int main(){ 
 int n, x; 
 queue <int> q; 
    cin >> n; 
    while(n--){ 
        cin >> x; 
        q.push(x); 
        while(q.front() < x - 3000){ 
            q.pop(); 
    } 
    cout << q.size() << " "; 
    } 
};