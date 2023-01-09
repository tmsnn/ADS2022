#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000008;

int a[maxn];
int p[maxn];
vector <int> g[maxn]; 
vector <int> ans;
int cnt;

void dsu(){
    for(int i = 0; i < maxn; i++){
        p[i] = i;
        a[i] = 1;
    }
}

int getRoot(int v){
    if(p[v] == v) return v;
    else return p[v] = getRoot(p[v]);
}

bool merge_sort(int x, int y){
    int x1 = getRoot(x), y1 = getRoot(y);
    if(x1 == y1){
        return false;
    } else {
        if(a[x1] < a[y1]){
            p[x1] = y1;
        } else if(a[y1] < a[x1]){
            p[y1] = x1;
        } else {
            p[x1] = y1;
            a[y1] += 1;
        }
        return true;
    }
}

int main(){
    int n, m;
    cnt = 0;
    dsu();
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // reverse(g.begin(), g.end());
    for(int i = n; i > 1; i--){
        cnt += 1;
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] > i and getRoot(i) != getRoot(g[i][j])){
                cnt -= 1;
                merge_sort(i, g[i][j]);
            }
        }
        ans.push_back(cnt);
    }
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    cout << 0 << endl;
}