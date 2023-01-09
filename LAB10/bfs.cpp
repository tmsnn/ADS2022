#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

vector <int> g[maxn];
bool used[maxn];
// vector <int> p(maxn);
vector <int> d(maxn);

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    int start, end;
    cin >> start >> end;
    queue <int> q;
    q.push(start);
    used[start] = true;
 
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    if(used[end]){
        cout << d[end] << endl;
        return 0;
    } 
    cout << -1;
}