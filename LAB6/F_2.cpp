#include <bits/stdc++.h>
using namespace std;

struct Students {
    string first_name, last_name;
    double gpa;
};

bool cmp(Students a, Students b){
    if(a.gpa == b.gpa){
        if(a.first_name == b.first_name){
            return a.last_name > b.last_name;
        } else {
            return a.first_name>b.first_name;
        }
    }
    return a.gpa > b.gpa;
}

int partition(vector <Students> &v, int l, int h){
    Students p = v[h];
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(cmp(p, v[j])){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[h]);
    return i+1;
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

void quickSort(vector <Students> &v, int l, int h){
    if(l < h){
        int pivot = partition(v, l, h);
        quickSort(v, l, pivot - 1);
        quickSort(v, pivot + 1, h);
    }
}

int main(){
    int n, numOfSubjects; 
    cin >> n;
    vector <Students> v(n);
    for(auto &i : v){
        cin >> i.first_name >> i.last_name >> numOfSubjects;
        double sum = 0;
        double SumOfCredits = 0;
        for(int j = 0; j < numOfSubjects; j++){
            string attestation;
            int credits;
            cin >> attestation >> credits;
            sum += grade(attestation) * credits;
            SumOfCredits += credits;
        }
        i.gpa = sum / SumOfCredits;
    }

    quickSort(v, 0, v.size() - 1);
    for(auto i : v){
        cout << i.first_name << " " << i.last_name << " " << fixed << setprecision(3) << i.gpa << endl;
    }
}