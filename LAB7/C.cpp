#include <bits/stdc++.h>
using namespace std;

void mergeOne(int a[], int l,int mid, int r){
    int i = l; int k = l; int j = mid + 1;
    int c[r + 1];
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            c[k] = a[i];
            k++; i++;
        } else {
            c[k] = a[j];
            k++; j++;
        }
    }
    for(; i <= mid; i++){
        c[k] = a[i];
        k++;
    }
    for(; j <= r; j++){
        c[k] = a[j];
        k++;
    }
    for(i = l; i <= r; i++){
        a[i] = c[i];
    }

}

void merge(int a[], int l,int r){
    if(l < r){
        int mid = (l + r) / 2;
        merge(a, l, mid);
        merge(a, mid + 1, r);
        mergeOne(a, l, mid, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[m];
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }
    int l, mida, midb, r, r1;
    l = 0; r = n - 1; r1 = m - 1;
    merge(a, l,r);
    merge(b, l,r1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                cout << a[i] << " ";
                b[j] = -598;
                i++;
                continue;
            }
        }
    }
}