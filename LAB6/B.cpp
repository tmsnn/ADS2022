#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &v, int l, int h){
    int pivot = v[h];
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[h]);
    return i + 1;
}

void quick_sort(vector <int> &v, int l, int h){
    if(l >= h){
        return;
    }
    int pivot = partition(v, l, h);
    quick_sort(v, l, pivot - 1);
    quick_sort(v, pivot + 1, h);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> v1;
    vector <int> v2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v1.push_back(x);
    }
    for(int j = 0; j < m; ++j){
        int y; cin >> y;
        v2.push_back(y);
    }

    quick_sort(v1, 0, v1.size() - 1);
    quick_sort(v2, 0, v2.size() - 1);

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(v1[i] == v2[j]){
                cout << v2[j] << " ";
                v1[i] = INT_MIN;
                break;
            }
            // v1[i] = INT_MIN;
            // break;
        }
        // break;
    }
    // for(int i = 0; i < n; i++){
    //     cout << v1[i] << " ";
    // }
    // cout << endl;
    // for(int j = 0; j < m; j++){
    //     cout << v2[j] << " ";
    // }
}