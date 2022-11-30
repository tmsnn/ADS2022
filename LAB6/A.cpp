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
    string s; cin >> s;
    vector <char> v1;
    vector <char> v2;
    // quick_sort(v1, 0, v1.size());
    // quick_sort(v2, 0, v2.size());

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u'){
            v1.push_back(s[i]);
        } else {
            v2.push_back(s[i]);
        }
    }

    quick_sort(v1, 0, v1.size() - 1);
    quick_sort(v2, 0, v2.size() - 1);

    for(int i = 0; i < v1.size(); i++){
        cout << v1[i];
    }
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i];
    }
}