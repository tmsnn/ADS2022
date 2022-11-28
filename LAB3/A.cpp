#include <bits/stdc++.h>

using namespace std;
int main() {
    int num, n, m;
    cin >> num;
    int numbers[num];
    for(int i = 0 ; i < num ; i++)
        cin >> numbers[i];
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < m;  j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < num ; i++) {
        int x = numbers[i];
        int l_i = 0, r_i = n, l_j = 0, r_j = m;
        while(l_i + 1 < r_i) {
            int mid = (l_i + r_i)/2;
            int midNum;
            if(mid % 2 == 0) {
                midNum = arr[mid][0];
            } else {
                midNum = arr[mid][m-1];
            }
            if(midNum >= x) l_i = mid;
            else r_i = mid; 
        }
        
        if(l_i % 2 == 0) {
            while(l_j + 1 < r_j) {
                int mid = (l_j + r_j) / 2;
                int midNum = arr[l_i][mid];
                if(midNum >= x)
                    l_j = mid;
                else
                    r_j = mid;
            }
        } else {
            while(l_j + 1 < r_j) {
                int mid = (l_j + r_j)/2;
                int midNum = arr[l_i][mid];
                if(midNum <= x)
                    l_j = mid;
                else
                    r_j = mid;
            }
        }
        int ans = arr[l_i][l_j];
        if(ans == x) cout << l_i << " " << l_j << endl;
        else cout << -1 << endl;
    }
    return 0; 
}