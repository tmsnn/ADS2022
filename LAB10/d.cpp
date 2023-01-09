#include <bits/stdc++.h>
using namespace std;

vector <int> g[5008];
bool used[5008];
int d[5008], colors[5008], n;

void bfs(int val){
    for(int i = 0; i <= n; i++){
        used[i] = 0;
    }
    queue <int> q;
    q.push(val);
    d[val] = 0;
    used[val] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); ++i){
            int to = g[v][i];
            if(d[to] > d[v] + 1){
                d[to] = d[v] + 1;
                used[to] = 1;
                q.push(to);
            }
        }
        // q.pop();
    }
}

int main(){
    int m, q; cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        d[i] = 1e9;
    }
    for(int k = 1; k <= q; k++){
        int type, v; cin >> type >> v;
        if(type == 1){
            if(colors[v] != 1){
                bfs(v);
                colors[v] = 1;
            }
        } else {
            if(d[v] == 1e9){
                cout << -1 << endl;
            } else cout << d[v] << endl;
        }
    }
}