#include <bits/stdc++.h>
using namespace std;

map <int, bool> used;
queue <int> q;
map <int, int> mp;

void bfs(int a, int b){
    q.push(a);
    used[a] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(!used[2 * v] and v < b){
            q.push(2 * v);
            used[2 * v] = true;
            mp[2 * v] = v;
            if(2 * v == b){
                return;
            }
        }
        if(v - 1 > 0 and !used[v - 1]){
            q.push(v - 1);
            used[v - 1] = true;
            mp[v - 1] = v;
            if(v - 1 == b){
                return;
            }
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    vector <int> ans;
    if(a > b){
        cout << a - b << endl;
        a--;
        while(a != b){
            cout << a << " ";
            a--;
        }
        cout << b; 
        return 0;
    }
    else if(a == b){
        cout << 0;
        return 0;
    }
    bfs(a, b);
    while( b != a){
        ans.push_back(b);
        b = mp[b];
    }
    cout << ans.size() << endl;

    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}