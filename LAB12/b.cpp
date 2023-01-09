#include <bits/stdc++.h>
using namespace std; 

int INF = 1000000008; 
vector<pair<int,int>> g[200008]; 
vector<int> d(200008, INF); 
int n,m; 

int dijkstra(int s, int end){ 
    d.clear(); 
    for(int i = 0; i < 200005; i++){ 
        d[i] = INF; 
    } 
    d[s] = 0; 
    set <pair<int,int> > q; 
    q.insert(make_pair(d[s],s)); 
    while(!q.empty()){ 
        int v = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j<g[v].size();j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(d[v] + len < d[to]){ 
                q.erase(make_pair(d[to], to)); 
                d[to] = d[v] + len; 
                q.insert(make_pair(d[to], to)); 
            } 
        } 
    } 
    return d[end]; 
} 



int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int u,v,c; 
        cin >> u >> v >> c; 
        g[u].push_back({v,c}); 
        g[v].push_back({u,c}); 
    } 
    int s, a, b, f; 
    cin >> s >> a >> b >> f; 
    int x, y; 
    x = dijkstra(s, a) + dijkstra(a,b) + dijkstra(b,f); 
    y = dijkstra(s, b) + dijkstra(b,a) + dijkstra(a,f) ; 
    if(min(x, y) <= INF) cout << min(x, y);
    else cout << -1; 
    return 0; 
}