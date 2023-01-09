#include <bits/stdc++.h>
using namespace std;
vector <int> v;
void add(int x){
    v.push_back(x);
}
void pop(){
    v.pop_back();
}
void getCur(){
    if(!v.empty()){
        cout << v[v.size()-1] << endl;
    }
    else cout << "error" << endl;
}

void getMax(){
    long long mx = INT_MIN;
    if(v.size()){
        for(int i=0;i<v.size();++i){
            if(v[i] > mx){
                mx = v[i];
            }
        }
        cout << mx << endl;
    } else {
    cout << "error" << endl;
}
}

int main(){
    int n, x;
    string s;
    cin >> n;

    while(n--){
        cin >> s;
        if(s == "add"){
            cin >> x;
            add(x);
        }
        else if(s == "delete"){
            pop();
        }
        else if(s == "getcur"){
            getCur();
        }
        else if(s == "getmax"){
            getMax();
        }
    }
}