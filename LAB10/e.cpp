#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[1008][1008];
bool used[1008][1008];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) used[i][j] = true;
        }
    }

    for(int i = 1; i <= q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(a[x][y] and a[y][z] and a[x][z]){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}