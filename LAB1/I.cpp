#include <bits/stdc++.h> 
using namespace std; 
int main (){ 
    int n; cin >> n; 
    string s; 
    cin >> s; 
    deque <int> d1; 
    deque <int> d2; 
    for (int i = 0; i < s.size(); i++){ 
        if (s[i] == 'S'){ 
            d1.push_back(i); 
        } else { 
            d2.push_back(i); 
        } 
    } 
    while(!d1.empty() && !d2.empty()){ 
        int i = d1.front(); 
        int j = d2.front(); 
        if (i < j){ 
            d2.pop_front(); 
            d1.push_back(i + n); 
            d1.pop_front(); 
        } else{ 
            d1.pop_front(); 
            d2.push_back(j + n); 
            d2.pop_front(); 
        } 
    } 
    cout << (d2.empty() ? "SAKAYANAGI" : "KATSURAGI");
}