#include <bits/stdc++.h>
using namespace std;

long long powof_primes[55];

void conv(long long prime){
    powof_primes[0] = 1;
    for (int i = 1; i <= 55; i ++){
        powof_primes[i] = powof_primes[i - 1] * prime;
    }
}

int main() {
    long long prime = 2;
    conv(prime);
    int n; cin >> n;

    vector<long long> hashes(n);
    for (int i = 0; i < n; i++){
        cin >> hashes[i];
    }
    for (int i = 0; i < n; i ++){
        if(!i){
            cout << char(hashes[i] / powof_primes[i] + 97);
        } else {
            cout << char((hashes[i] - hashes[i - 1]) / powof_primes[i] + 97);
        }
    }
}