#include <iostream> 
#include <math.h> 
#include <deque> 
using namespace std; 
int main() { 
    deque<int> deq1(5); 
    deque<int> deq2(5); 
    for (int i = 0; i < 5; i ++){ 
        cin >> deq1[i]; 
    } 
    for (int i = 0; i < 5; i ++){ 
        cin >> deq2[i]; 
    } 
    int cnt = 0; 
    while(!deq1.empty() && !deq2.empty() && cnt < 1000000){ 
        cnt++; 
        int a = deq1.front(); 
        int b = deq2.front(); 
        deq1.pop_front(); 
        deq2.pop_front(); 
        if (a == 0 && b == 9){ 
            deq1.push_back(a); 
            deq1.push_back(b); 
        } 
        else if (a == 9 && b == 0){ 
            deq2.push_back(a); 
            deq2.push_back(b); 
        } 
        else if (a > b){ 
            deq1.push_back(a); 
            deq1.push_back(b); 
        } 
        else{ 
            deq2.push_back(a); 
            deq2.push_back(b); 
        } 
    } 
    if (deq1.empty()){ 
        cout << "Nursik " << cnt; 
    } 
    else if (deq2.empty()){ 
        cout << "Boris " << cnt; 
    } 
    else{ 
        cout << "blin nichya"; 
    } 
    return 0; 
}
// cout << player1.empty() ? "Nursik " + cnt : player2.empty() ? "Boris " + cnt : "blin nichya";