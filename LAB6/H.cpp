#include <bits/stdc++.h>
using namespace std;

int partition(vector <char> &v, int l, int h){
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

void quick_sort(vector <char> &v, int l, int h){
    if(l >= h){
        return;
    }
    int pivot = partition(v, l, h);
    quick_sort(v, l, pivot - 1);
    quick_sort(v, pivot + 1, h);
}

int main(){
    int n; cin >> n;
    vector <char> v;
    for(int i = 0; i < n; i++){
        char a; cin >> a;
        v.push_back(a);
    }
    char x; cin >> x;
    quick_sort(v, 0, v.size() - 1);

    if(v[v.size() - 1] <= x){
        cout << v[0];
    } else {
        for(int i = 0; i < v.size(); i++){
        if(v[i] > x){
            cout << v[i];
            break;
        }
    }
    }
}