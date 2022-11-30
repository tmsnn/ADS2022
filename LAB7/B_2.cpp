#include <bits/stdc++.h>
using namespace std;
int c[10000028];
void merge(int a[], int b[], int n, int m){
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            c[k] = a[i];
            k++; i++;
        } else {
            c[k] = b[j];
            k++; j++;
        }
    }
    for(; i < n; i++){
        c[k] = a[i];
        k++;
    }
    for(; j < m; j++){
        c[k] = b[j];
        k++;
    }
}

int main(){
    int n, m; cin >> n;
    int a[n];
    // vector <int> a;
    // vector <int> b;
    for(int i = 0; i < n; i++){
        // int x; cin >> x;
        // a.push_back(x);
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for(int j = 0; j < m; j++){
        // int x; cin >> x;
        // b.push_back(x);
        cin >> b[j];
    }
    merge(a, b, n, m);
    for(int k = 0; k < n + m; k++){
        cout << c[k] << " ";
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for(int j = 0; j < m; j++){
    //     cout << b[j] << " ";
    // }
}