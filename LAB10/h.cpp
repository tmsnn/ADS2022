#include <bits/stdc++.h>
using namespace std;

char g[105][105];
bool used[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

void dfs(int i, int j){
    used[i][j] = true;
    for(int k = 0; k < 4; k++){
        int i2 = i + dx[k];
        int j2 = j + dy[k];
        if(i2 >= 0 && i2 < n && j2 >= 0 && j2 < m && g[i2][j2] == '1' && !used[i2][j2]){
            dfs(i2, j2);
        }
    }
}

int main(){
    // int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!used[i][j] && g[i][j] == '1'){
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
}