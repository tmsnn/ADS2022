#include <bits/stdc++.h>
using namespace std;

int partition(int a1[], int l, int h){
    int pivot = a1[h];
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(a1[j] < pivot){
            i++;
            swap(a1[i], a1[j]);
        }
    }
    swap(a1[i + 1], a1[h]);
    return i + 1;
}

void quick_sort(int a1[], int l, int h){
    if(l >= h){
        return;
    }
    int pivot = partition(a1, l, h);
    quick_sort(a1, l, pivot - 1);
    quick_sort(a1, pivot + 1, h);
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    vector <int> colomn;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < m; i++){
        int a1[n];
        for(int j = 0; j < n; j++){
            a1[j] = a[j][i];
        }
        quick_sort(a1, 0, n - 1);
        for(int j = 0; j < n; j++){
            a[j][i] = a1[j];
        }
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            cout  << a[i][j] << " ";
        }
        cout << endl;
    }
    
}