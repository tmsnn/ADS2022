#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[508];
vector <int> pathOfCycle;
stack <int> st;
int used[508];
 
bool dfs(int v, int x, int y){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(v == x && y == to){
            continue;
        }
        if(!used[to]){
            if(dfs(to, x, y)) return true;
        } else if(used[to] == 1){
            return true;
        }
    }
    used[v] = 2;
    return false;
}

bool dfs2(int v){
    used[v] = 1;
    st.push(v);
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]){
            if(dfs2(to)) return true;
        } else if(used[to] == 1){
            while(st.top() != to){
                pathOfCycle.push_back(st.top());
                st.pop();
            }
            pathOfCycle.push_back(to);
            pathOfCycle.push_back(v);
            reverse(pathOfCycle.begin(), pathOfCycle.end());
            return true;
        }
    }
    used[v] = 2;
    if(!st.empty()) st.pop();
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    bool cyclic = false;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cyclic = dfs2(i);
            if(cyclic) break;
        }
    }
    if(!cyclic) {
        cout << "YES";
        return 0;
    }
    for(int i = 0; i < pathOfCycle.size() - 1; i++){
        int u = pathOfCycle[i];
        int v = pathOfCycle[i + 1];
        for(int j = 1; j <= n; j++){
            used[j] = 0;
        }
        cyclic = 0;
        for(int j = 1; j <= n; j++){
            if(!used[j]){
                cyclic |= dfs(j, u, v);
            }
        }
        if(!cyclic){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO"; 
}