#include <bits/stdc++.h>
using namespace std; 

const int maxn = 408;
vector <int> roadways[maxn]; 
vector <int> airways[maxn]; 
int a[maxn][maxn]; 

int main(){ 
    int n,m; 
    cin >> n >> m; 
    queue <int> q; 
    queue <int> q1; 
    vector <int> d(n + 1); 
    vector <int> d1(n + 1); 
    vector <bool> used(n + 1);
    vector <bool> used1(n + 1); 
    for(int i = 0; i < m; i++){ 
        int x, y; 
        cin >> x >> y; 
        x -= 1; y -= 1; 
        roadways[x].push_back(y); 
        roadways[y].push_back(x); 
        a[x][y] = 1; 
        a[y][x] = 1; 
    } 

    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (a[i][j] == 0 && i != j){ 
                airways[i].push_back(j); 
            } 
        } 
    } 
 
    q.push(0); 
    used[0] = true; 
    while(!q.empty()){ 
        int v = q.front(); 
        q.pop(); 
        for(int i = 0; i < roadways[v].size(); i++){ 
            int to = roadways[v][i]; 
            if(!used[to]){ 
                used[to] = true; 
                q.push(to); 
                d[to] = d[v]+1; 
            } 
        } 
    } 

    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < airways[v].size(); i++){ 
            int to = airways[v][i]; 
            if(!used1[to]){ 
                used1[to] = true; 
                q1.push(to); 
                d1[to] = d1[v] + 1; 
            } 
        } 
    } 
    if (!used[n-1] || !used1[n-1]){ 
        cout << -1; 
    } else { 
        cout << max(d[n-1], d1[n-1]); 
        return 0;
    } 
}