#include <bits/stdc++.h>
using namespace std;

int partition(vector <pair<string, string>> &v, int l, int h){
    int pivot = h;
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(v[j].first < v[pivot].first){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[h]);
    return i + 1;
}

void quick_sort(vector <pair<string, string>> &v, int l, int h){
    if(l >= h){
        return;
    }
    int pivot = partition(v, l, h);
    quick_sort(v, l, pivot - 1);
    quick_sort(v, pivot + 1, h);
}


int main(){
    int n; cin >> n;
    string s, s1;
    vector <pair<string, string>> v;
    // bool ok = true;
    // vector<pair<string, string>> v1;

    for(int i = 0; i < n; i++){
        cin >> s >> s1;
        bool ok = true;
        // v.push_back(make_pair(s, s1));
        if(!v.empty()){
            for(int j = 0; j < v.size(); j++){
            if(s == v[j].second){
                v[j].second = s1;
                ok = false;
            }
            }
            if(ok){
            v.push_back(make_pair(s, s1));
        }
        } else if(v.empty()){
            v.push_back(make_pair(s, s1));
        }
    }

    cout << v.size() << endl;
    quick_sort(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}