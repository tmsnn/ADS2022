#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    bool ok = false;;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            ok = true;
            break;
        }
    }
    if (n == 1) return false;
    if (ok == false){
        return true;
    } else{
        return false;
    }
}

int main(){
    // int cnt = 1;
    int n; cin >> n;

    vector <int> v;
    vector <int> a;
    int i = 1;

    a.push_back(2);

    while(i <= 100000) {
        if (isPrime(i)) {
            // cnt += 1;
            a.push_back(i);
        }        
        i++;
    }

    for (int i = 1; i < a.size(); i++){
        if (isPrime(i)) v.push_back(a[i]);
    }

    for (int i = 1; i < v.size(); i++){
        if(i == n) cout << v[i-1];
    }
}
