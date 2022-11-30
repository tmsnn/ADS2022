#include <bits/stdc++.h>
using namespace std;

bool comp(string &s1, string &s2){
    return s1.size() > s2.size();
}

void mergeOne(vector <string> &v, int l, int mid, int r){
    int i = l;int k = 0; int j = mid + 1;
    string c[r + 1];
    while(i <= mid && j <= r){
        if(comp(v[i], v[j])){
            c[k] = v[j];
            k++; j++;
        } else {
            c[k] = v[i];
            k++; i++;
        }
    }
    for(; i <= mid; i++){
        c[k] = v[i];
        k++;
    }
    for(; j <= r; j++){
        c[k] = v[j];
        k++;
    }
    for(i = l; i <= r; i++){
        v[i] = c[i - l];
    }

}

void merge(vector <string> &v, int l,int r){
    if(l < r){
        int mid = (l + r) / 2;
        merge(v, l, mid);
        merge(v, mid + 1, r);
        mergeOne(v, l, mid, r);
    }
}


int main() {
  int n; cin >> n;
  for (int k = 1; k <= n; k++){
    string s;
    getline(cin >> ws, s);
    vector <string> v;
    string t = "";
    for (int i = 0; i < s.size(); i ++){
      if (s[i] == ' '){
        v.push_back(t);
        t = "";
        continue;
      }
      t += s[i];
    }
    v.push_back(t);
    
    merge(v, 0, v.size()-1);
    for (int i = 0; i < v.size(); i ++)
        cout << v[i] << " ";

    cout << endl;
  }
}