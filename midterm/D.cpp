#include <bits/stdc++.h>
using namespace std;
void check(int n, map <int, bool> check_to_prime, int cnt){
    if (n < 2) { 
        cout << 0; 
        return; 
    } 
    for(int i = 2; i * i <= n; i++) 
    { 
        while(n % i == 0) 
        { 
            if(!check_to_prime[i]) 
            { 
                cnt++;
                check_to_prime[i] = true; 
            } 
            n /= i; 
        } 
    } 
    if(n > 2) cnt++;
cout << cnt;
}

int main(){
    int n; 
    cin >> n;
    map <int, bool> check_to_prime; 
    int cnt = 0;
    check(n, check_to_prime, cnt);
}
