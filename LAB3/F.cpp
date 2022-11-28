#include <bits/stdc++.h>
using namespace std;

bool binsearch(int a[], int n, int num){
        int l = 0, r = n - 1, sum = 0, cnt = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid] >= num){
                cnt++;
                sum += a[mid];
            }
            else if(a[mid] < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << cnt << " " << sum;
    }

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k; cin >> k;
    int num;
    while(cin >> k){
        cin >> num;
        n--;
    }
    binsearch(a, n, num);
}