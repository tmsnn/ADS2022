#include <bits/stdc++.h>
using namespace std;

int cnt = 0; 
const int MAXN = 100009;
vector <int> g[MAXN];
bool used[MAXN];

void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(g[to].size() > g[v].size()){
            cnt += 1;
        }
        dfs(to);
    }
    return;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x--].push_back(y--);
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cnt += 1;
            dfs(i);
            // cnt += 1;
        }
    }
    cout << cnt;
}