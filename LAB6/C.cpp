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
    if(l < h){
        int pivot = partition(v, l, h);
        quick_sort(v, l, pivot - 1);
        quick_sort(v, pivot + 1, h);
    }
}

int main(){
    int n, x; cin >> n;
    vector <int> v;
    vector <pair<int, int>> v1;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    quick_sort(v, 0, n - 1);
    int min = abs(v[0] - v[1]);
    for(int i = 1; i < n; i++){
        if(abs(v[i] - v[i - 1]) < min){
            min = abs(v[i] - v[i - 1]);
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(abs(v[i] - v[i + 1]) == min){
            v1.push_back({v[i], v[i + 1]});
        }
    }

    for(int i = 0; i < v1.size(); i++){
        cout << v1[i].first << " " << v1[i].second << " ";
    }
    // for(int i = 0; i < n; i++){
    //     cout << v[i] << " ";
    // }
}