#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int INF = 1e9 + 5;;
bool used[maxn];

vector <pair<int, int>> g[maxn];
int d[maxn];
int n, m;
set <pair<int, int>> setik;

void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        if(i == s){
            d[i] = 0;
        } else d[i] = INF;
    }
    d[s] = 0;

    for(int i = 0; i < n; i++){
        int u =  -1;    
        for(int j = 1; j <- n; j++){
            if(!used[j] && (u == -1 || d[j] < d[u])){
                u = j;
            }
        }
        if(d[u] == INF) break;
        used[u] = true;

        for(int j = 0; j < g[u].size(); j++){
            pair <int, int> p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));

    }
    dijkstra(1);
    for(int i = 1; i < )
}