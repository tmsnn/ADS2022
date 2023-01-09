#include <bits/stdc++.h>
using namespace std;

const int maxn = 1008;

int a[maxn];
int p[maxn];
vector <pair<int, pair <int, int>>> graph; 

void dsu(){
    for(int i = 0; i < maxn; i++){
        p[i] = i;
        a[i] = 1;
    }
}

int getRoot(int v){
    if(p[v] == v){
        return v;
    } else {
        return p[v] = getRoot(p[v]);
    }
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
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    int mst = 0;
    for(int i = 1; i <= m; i++){
        string asphalt;
        int a, b, c; cin >> asphalt >> a >> b >> c;
        if( asphalt == "both"){
            graph.push_back({c * min(x, y), {b, a}});
            graph.push_back({c * min(x, y), {a, b}});
        } else if(asphalt == "big"){
            graph.push_back({c * x, {a, b}});
            graph.push_back({c * x, {b, a}});
        } else if(asphalt == "small"){
            graph.push_back({c * y, {a, b}});
            graph.push_back({c * y, {b, a}});
        }
    }
    sort(graph.begin(), graph.end());
    dsu();

    for(int i = 0; i < graph.size(); i++){
        if(merge_sort(graph[i].second.first, graph[i].second.second)){
            mst += graph[i].first;
        }
    }

    cout << mst << endl;
}