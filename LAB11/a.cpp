#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000008;
long long min_ans = 0;
vector <pair <int, pair <int, int>>> graph;
int n, m;
vector <int> p;

int dsu(int v){
    if(v == p[v]){
        return v;
    } else {
        return p[v] = dsu(p[v]);
    }
}

void dsu_join(int a, int b){
    a = dsu(a);
    b = dsu(b);
    p[a] = b;
}

int main(){
    cin >> n >> m;
    p.resize(n);
    while(m--){
        int l, r, c;
        cin >> l >> r >> c;
        l -= 1;
        r -= 1;
        graph.push_back(make_pair(c, make_pair(l, r)));
    }
    sort(graph.begin(), graph.end());

    for(int i = 0; i < n; i++){
        p[i] = i;
    }

    for(int i = 0; i < graph.size(); i++){
        int x = graph[i].second.first; 
        int y = graph[i].second.second;
        int cost = graph[i].first;

        for(int j = x + 1; j <= y; j++){
            if(dsu(x) != dsu(j)){
                dsu_join(x, j);
                min_ans += cost;
            } else {
                j = p[x];
            }
        }
    }
    cout << min_ans << endl;
}