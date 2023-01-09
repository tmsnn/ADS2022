#include <bits/stdc++.h>
using namespace std;

vector <int> g[100008];
bool used[100008];

void dfs(int v){
    // cout << v << endl;
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;
    dfs(s);
    if(used[s] && used[f]){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}