// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int val = val;
//     Node * next = next;
//     Node * prev = prev;
//     Node(int val){
//         this -> val = val;
//         this -> next = nullptr;
//         this -> prev = nullptr;
//     }
// };
// struct LinkedList{
// private:
//     Node* head = nullptr;
//     Node* tail = nullptr;
// public: 
//     void push_front(int val){
//         Node * newNode = new Node(val);
//         if(head == nullptr){
//             head = tail = newNode;
//         } else {
//             head -> prev = newNode;
//             newNode -> next = head;
//             head = newNode;
//         }
//     }
    
//     void push_back(int val){
//         Node * newNode = new Node(val);
//         if(head == nullptr){
//             head = tail = newNode;
//         } else {
//             tail -> next = newNode;
//             newNode -> prev = tail;
//             tail = newNode;
//         }
//     }
   
//     void print(int cnt){
//         if(cnt % 2 == 0){
//             Node * cur = head;
//             while(cur != nullptr){
//             cout << cur -> val << " ";
//             cur = cur -> next;
//         }
//         } else {
//             Node * cur = tail;
//             while(cur != nullptr){
//             cout << cur -> val << " ";
//             cur = cur -> prev;
//         }

//     }
// }
// };

// int main(){
//     int cnt = 0;
//     bool reverse = false;
//     LinkedList list;
//     int n; cin >> n;
//     int x, m;
//     while(n--){
//         cin >> x;
//         if(x == 2){
//             cnt++;
//         }
//         cout << cnt << endl;
//         if(x == 1){
//             cin >> m;
//             if(cnt % 2 == 0){
//                 list.push_front(m);
//             } else {
//                 list.push_back(m);
//             }
//         }
//     }
//     list.print(cnt);
// }
#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;



vector <long long> getPrefHashes(vector <int> hash){
    for(int i = 0; i < hash.size(); i++){
        
    }
}

int main(){
    vector <int> hash;

}