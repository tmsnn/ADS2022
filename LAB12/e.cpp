#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000008;
struct graph {
    int a, b, cost;
};

int n, v;
vector <graph> e;
bool cycle = false;
void solve(){
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p (n, -1);
    int x;

    for (int i = 0; i < n; ++i) {
        x--;
        for (int j = 0; j < n * n; ++j){
            if (d[e[j].a] < INF){
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }

    if (x == -1) cycle = false;
    else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> mst;
        for (int cur = y; ; cur = p[cur]) {
            mst.push_back (cur);
            if (cur == y && mst.size() > 1)  break;
        }
        reverse (mst.begin(), mst.end());
        cout << "YES" << endl;
        cout << mst.size() << endl;
        for (size_t i = 0; i < mst.size(); ++i){
            cout << mst[i] + 1 << " ";
        }
        cout << endl;
        cycle = true;
    }
}

int main(){
    cin >> n;
    vector <int> d(n, INF);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            graph cur;
            cin >> cur.cost;
            cur.a = i; cur.b = j;
            e.push_back(cur);
        }
    }

    for (int i = 0; i < n; i ++){
        v = i;
        solve();
        if (cycle) break;
    }
    if(!cycle){
        cout << "NO" << endl;
    }
}