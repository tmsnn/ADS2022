#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10009;
vector <int> g[105];
bool used[MAXN];

void dfs(int v){
    cout << v << endl;
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    }
}