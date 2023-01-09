#include <bits/stdc++.h>
using namespace std;

const int maxn = 1008;

int a[maxn][maxn];
bool used[maxn][maxn];

int n, m;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main(){
    cin >> n >> m;
    vector <queue<pair<int, int>>> v;
    int mushrooms = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                v.push_back(queue<pair <int, int>>());
                v[v.size() - 1].push({i, j});
                used[i][j] = true;
            }
            else if(a[i][j] == 1){
                mushrooms += 1;
            }
        }
    }
    if(mushrooms == 0){
        cout << 0 << endl;
        return 0;
    }
    int step = 0;
    while(true){
        bool empty = true;
        for(int i = 0; i < v.size(); i++){
            if(!v[i].empty()){
                queue <pair <int, int>> cur = v[i];
                while(!cur.empty()){
                    empty = false;
                    int v_x = cur.front().first;
                    int v_y = cur.front().second;
                    cur.pop();
                    v[i].pop();
                    for(int k = 0; k < 4; k++){
                        int to_x = v_x + x[k];
                        int to_y = v_y + y[k];
                        if(to_x > 0 && to_y > 0 && to_x <= n and to_y <= m){
                            if(!used[to_x][to_y] && a[to_x][to_y] != 0){
                                used[to_x][to_y] = true;
                                if(a[to_x][to_y] == 1){
                                    mushrooms--;
                                    if(mushrooms == 0){
                                        cout << step + 1 << endl;
                                        return 0;
                                    }
                                }
                                a[to_x][to_y] = 2;
                                v[i].push({to_x, to_y});
                            }
                        }
                    }
                }
            }
        }
        if(empty) break;
        step++;
    }
    cout << -1;
}