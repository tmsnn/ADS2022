#include <bits/stdc++.h>
using namespace std;

long long getWorkTime(vector <long long> &islands, long long bucketSize) {
    long long timeToWork = 0;
    for(auto i : islands) {
        timeToWork += i/bucketSize;
        if(i%bucketSize){
            timeToWork++;
        }
    }
    return timeToWork;
}

int main(){
    long long n, f;
    cin >> n >> f;
    vector <long long> islands(n);
    for(long long &island: islands)
        cin >> island;

    long long l = 0, r = 1e18+123;

    while(l + 1 < r) {
        long long mid = (l+r)/2;
        long long timeToSanta = getWorkTime(islands, mid);
        if(timeToSanta <= f){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
    return 0;
}