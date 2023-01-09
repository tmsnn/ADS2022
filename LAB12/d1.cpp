#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000008;
vector<pair<int, int>> graph[maxn];
bool used[maxn];

int main(){
    int n;
    cin >> n;
    int arr[n][n];
    int ans = 0;
     priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            graph[i].push_back({j, arr[i][j]});
            graph[j].push_back({i, arr[i][j]});
        }
    }
    
    q.push({0, 1});

    while(!q.empty()){
        pair <int,int> p = q.top();
        q.pop();
        int v = p.second;
        int mst = p.first;
        
        if(used[v]){
            continue;
        }
        ans += mst;
        used[v] = true;
        

        for(pair<int, int> i : graph[v]){
            int u = i.first, length = i.second;
            if(!used[u]){
                q.push({length, u});
            }
        }
    }
    cout << ans << endl;
    return 0;
}