#include <bits/stdc++.h>  
using namespace std;  
int main(){  
  int n;  
  cin >> n;  
  vector <int> primes;
//   for(int i = 2; i <= n / 2; i++)  
//     {  
//       if(n % i != 0){ 
//         primes.push_back(n);
//         }  
//     }  
//   for(int i = 0; i < primes.size(); i++){
//     cout << primes[i] << " ";
//   }
int i = 2;
while(n >= 1){
    if(n % i != 0){
        primes.push_back(n);
        i++;
        n--;
    }
}
reverse(primes.begin(), primes.end());
for(int i = 0; i < primes.size(); i++){
    cout << primes[i] << " ";
}
}
