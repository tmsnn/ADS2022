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
    string s; cin >> s;
    vector <char> v;
    for(int i = 0; i < s.size(); ++i){
        v.push_back(s[i]);
    }
    quick_sort(v, 0, v.size() - 1);

    // int i = 0;
   
    for(int i = 0; i < v.size(); ++i){
        cout << v[i];
    }
}