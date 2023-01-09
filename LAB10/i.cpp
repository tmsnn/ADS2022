#include <bits/stdc++.h>
using namespace std;

int m, n;
vector <int> g[100008];

int zero = 0;
int one = 1;
int two = 2;


vector <int> cycle;
int used[100008];

void dfs(int v){
    // cout << v << endl;
    if(used[v] == one){
        cout << "Impossible";
        exit(0);
    }

    if(used[v] == two) return;
    used[v] = one;
    
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    used[v] = two;
    cycle.push_back(v);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(used[i] == zero){
            dfs(i);
        }
    }
    cout << "Possible" << endl;
    for(int i = cycle.size() - 1; i >= 0; i--){
        cout << cycle[i] << " ";
    } 

}