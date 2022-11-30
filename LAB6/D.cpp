#include <bits/stdc++.h>
using namespace std;

bool cmp(string &s, string &s1){
    string year = s.substr(6, 4);
    string month = s.substr(3,2);
    string day = s.substr(0,2);

    string year1 = s1.substr(6, 4);
    string month1 = s1.substr(3,2);
    string day1 = s1.substr(0,2);

    if (year > year1) return true;
    if (year < year1) return false;
    if (month > month1) return true;
    if (month < month1) return false;
    if (day > day1) return true;
    if (day < day1) return false;
    return false;

}

int partition(vector <string> &v, int l, int h){
    string pivot = v[h];
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(cmp(pivot, v[j])){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[h]);
    return i + 1;
}

void quick_sort(vector<string> &v, int l, int h){
    if(l >= h){
        return;
    }
    int pivot = partition(v, l, h);
    quick_sort(v, l, pivot - 1);
    quick_sort(v, pivot + 1, h);
}

int main(){
    int n; cin >> n;
    string s;
    vector <string> v;
    
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    quick_sort(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    } 
}