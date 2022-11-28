#include <bits/stdc++.h>
using namespace std;

long long getBlocksCount(vector <long long> &nums, long long sz) {
    long long cur = 0, res = 0;
    for(auto i : nums) {
        if(i > sz)
            return 1e18+123;
        if(cur + i > sz) {
            res++;
            cur = i;
        } else {
            cur += i;
        }
    }
    if(cur){
        res++;
    }
    return res;
}

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for(auto &i: nums){
        cin >> i;
    }
    long long l = 0, r = 1e18+123;
    while(l + 1 < r) {
        long long mid = (l+r)/2;
        long long blocks = getBlocksCount(nums, mid);
        if(blocks <= k){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
    return 0;
}