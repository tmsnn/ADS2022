#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 5;
const int INF = 1e9;

int d[MXN];
vector<pair<int, int> > g[MXN];
int n;
set<pair<int, int> > st;

void dijk(int s){
    for(int i = 1; i <= n; i++){
        if(i == s) d[i] = 0;
        else{
            d[i] = INF;
        }
        st.insert(make_pair(d[i], i));
    }

    for(int i = 0 ; i < n; i++){
        pair <int, int> p = *(st.begin());
        st.erase(p);
        int a = p.second, b = p.first;
       
        if(b == INF) break;

        for(int j = 0; j< g[a].size(); j++){
            p = g[a][j];

            int v = p.first, u = p.second;

            if(d[v] > u && d[v] > d[a]){
                st.erase(make_pair(d[v], v));
                d[v] = max(d[a], u);
                st.insert(make_pair(d[v], v));
            }
        }
    }
}

int main(){

    cin >> n;
    pair<int, int> p[n];

    for(int i = 0; i < n ; i++){
        int x, y; cin >> x >> y;
        p[i] = make_pair(x, y);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
            g[i+1].push_back(make_pair(j+1, w));
            g[j+1].push_back(make_pair(i+1, w));
        }
    }
    
    dijk(1);

    cout << d[n];

    return 0;
}