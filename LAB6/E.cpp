#include <bits/stdc++.h>
using namespace std;

int a[10000][10000];
int partition(int row, int colomn, int h){
    int pivot = a[h][row];
    int i = colomn - 1;
    for(int j = colomn; j < h; j++){
        if(a[j][row] > pivot){
            i++;
            swap(a[i][row], a[j][row]);
        }
    }
    swap(a[i + 1][row], a[h][row]);
    return i + 1;
}

void quick_sort(int row, int colomn, int h){
    if(colomn <= h){
        return;
    }
    int pivot = partition(row, colomn, h);
    quick_sort(row, colomn, pivot - 1);
    quick_sort(row, pivot + 1, h);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    quick_sort(n, m, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}