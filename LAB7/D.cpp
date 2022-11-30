#include <bits/stdc++.h>
using namespace std;

struct Student{
    string first_name, last_name;
    double gpa;
};

bool cmp(Student a, Student b){
    if(a.gpa == b.gpa){
        if(a.first_name == b.first_name){
            return a.last_name > b.last_name;
        } else {
            return a.first_name>b.first_name;
        }
    }
    return a.gpa > b.gpa;
}

void mergeOne(vector<Student> &v, int m, int l, int r){
    int i = l, j = m + 1;
    vector <Student> v1;
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

void merge(vector <Student> &v, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        merge(v, l, m);
        merge(v, m+1, r);
        mergeOne(v, l, m, r);
    }
}

double grade(string attestation){
    if(attestation == "A+") return 4.00;
    else if(attestation == "A") return 3.75;
    else if(attestation == "B+") return 3.50;
    else if(attestation == "B") return 3.00;
    else if(attestation == "C+") return 2.50;
    else if(attestation == "C") return 2.00;
    else if(attestation == "D+") return 1.50;
    else if(attestation == "D") return 1.00;
    else if(attestation == "F") return 0;
}


int main(){
    int n;
    cin >> n;
    vector <Student> v(n);
    int numOfSubjects; 
    for(auto &i : v){
        cin >> i.first_name >> i.last_name >> numOfSubjects;
        double SumOfCredits = 0;
        double sum = 0;
        for(int j = 0; j < numOfSubjects; j++){
            string attestation;
            int credits;
            cin >> attestation >> credits;
            SumOfCredits += credits;
            sum += grade(attestation) * credits;

        }
        i.gpa = sum / SumOfCredits;
    }

    merge(v, 0, v.size() - 1);
    for(auto &i : v){
        cout << i.first_name << " " << i.last_name << " " << fixed << setprecision(3) << i.gpa << endl;
    }
}