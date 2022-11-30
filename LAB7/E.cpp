#include <bits/stdc++.h>
using namespace std;

struct rows{
    int sum;
    vector <int> v;
    rows(){
        this->sum = 0;
    }

    void push(int x){
        this->sum += x;
        this->v.push_back(x);
    }
    void print(){
        for(int i = 0; i < this->v.size(); i++){
            cout << this -> v[i] << " ";
        }
        cout << endl;
    }

    bool cmp(rows * v1){
        if(this -> sum > v1 -> sum)
            return true;
        if(this -> sum == v1 -> sum){
            for(int i = 0; i < this -> v.size(); i++){
                if(this -> v[i] != v1 -> v[i]){
                    return this -> v[i] < v1 -> v[i];
                }
            }
            return false;
        }
        return false;
    }
};

void merge_sort(rows * a, int l, int r, int l1, int r1){
    int n = r - l + 1;
    rows v[n]; 
    for(int i = 0; i < n; ++i){
        v[i] = a[l + i];
    }

    int n1 = r1 - l1 + 1;
    rows v1[n1];
    for(int i = 0; i < n1; ++i){
        v1[i] = a[l1 + i];
    }
    int i = l, j = 0, k = 0;

    while(j < n && k < n1){
        if(v[j].cmp(&v1[k])){
            a[i] = v[j];
            i++; j++;
        } else {
            a[i] = v1[k];
            i++; k++;
        }
    }
    
    while(j < n){
        a[i] = v[j];
        i++; j++;
    }
    
    while(k < n1){
        a[i] = v1[k];
        i++; k++;
    }
    
}

void merge(rows * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        merge(a, l, m);
        merge(a, m + 1, r);
        merge_sort(a, l, m , m + 1, r);
    }
}

int main(){
    int n, m, x;
    cin >> n >> m;
    rows rows[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            rows[i].push(x);
        }
    }
    merge(rows, 0, n - 1);
    for(int i = 0; i < n; i++){
        rows[i].print();
    }
}