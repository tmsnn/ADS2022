#include <bits/stdc++.h>
using namespace std;

struct Students {
    string first_name, last_name;
    double gpa;
};

bool cmp(Students s1, Students s2){
    if (s1.gpa == s2.gpa){
        if (s1.first_name == s2.last_name){
            return s1.last_name> s2.last_name;
        } else {
            return s1.first_name > s2.first_name; 
        }
    }
    return s1.gpa > s2.gpa;
}
void mergeOne(vector<Students> &v, int l, int m, int r){
    int i = l;
    int j = m + 1;
    vector <Students> v1;
    while(i <= m && j <= r){
        if(!cmp(v[i], v[j])){   
            v1.push_back(v[i]);
            i++;
        } else {
            v1.push_back(v[j]);
            j++;
        }
    }
    for(; i <= m; i++){
        v1.push_back(v[i]);
    }

    for(; j <= r; j++){
        v1.push_back(v[j]);
    }

    for(i = l; i <= r; i++){
        v[i] = v1[i - l];
    }

}

void merge(vector <Students> &v, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        merge(v, l, m);
        merge(v, m + 1, r);
        mergeOne(v, l, m, r);
    }
}

double grades(string s){
    if(s == "A+") return 4.00;
    if(s == "A") return 3.75;
    if(s == "B+") return 3.50;
    if(s == "B") return 3.00;
    if(s == "C+") return 2.50;
    if(s == "C") return 2.00;
    if(s == "D+") return 1.50;
    if(s == "D") return 1.00;
    if(s == "F") return 0;
    else return -1;
}


int main() {
    int n; cin >> n;
    vector <Students> v(n);
    int m;
    for (int i = 0; i < n; i++){
        cin >> v[i].first_name >> v[i].last_name >> m;
        double sumOfCredits = 0;
        double sum = 0;
        for (int j = 0; j < m; j++){
            string grade;
            int credits;
            cin >> grade >> credits;
            sumOfCredits += credits;
            sum += grades(grade) * credits;
        }
        v[i].gpa = sum / sumOfCredits;
    }

    merge(v, 0, v.size() - 1);
    for (int i = 0; i < n; i++){
        cout << v[i].first_name << " " << v[i].last_name<< " " << fixed << setprecision(3) << v[i].gpa << endl;
    }
}