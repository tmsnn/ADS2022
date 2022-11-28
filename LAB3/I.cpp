#include <bits/stdc++.h>
using namespace std;

bool binsearch(int a[],int n, int m){
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid] == m){
                cout << "Yes";
                return 0;
            }
            else if(a[mid] < m) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << "No";
    }
int main(){
    int n, x; cin >> n;
    // int a[n]
    int a[n]; 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sz = n;
    cin >> x;
    binsearch(a, n , x);
}