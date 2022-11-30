#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int partition (vector<int> &vec, int low, int high){
    int pivot = vec[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}


void quickSort(vector<int> &vec, int low, int high)
{
    if (low < high){
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i ++){
        cin >> vec[i];
    }
    quickSort(vec, 0, n - 1);
    vector<pair<int,int>> ans;
    int mn = abs(vec[0] - vec[1]);
    for (int i = 1; i < n; i ++){
        if (abs(vec[i] - vec[i - 1]) < mn){
            mn = abs(vec[i] - vec[i - 1]);
        }
    }
    for (int i = 0; i < n - 1; i ++){
        if (abs(vec[i] - vec[i + 1]) == mn){
            ans.push_back({vec[i], vec[i + 1]});
        }
    }

    for (auto [i, j] : ans){
        cout << i << " " << j << " ";
    }
}