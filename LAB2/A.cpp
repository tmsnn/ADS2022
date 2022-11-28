#include <bits/stdc++.h>
using namespace std;

struct Node { 
    int val; 
    Node* next; 
    Node* prev; 
    Node (int x) { 
        this->val = x; 
        this->next = nullptr; 
        this->prev = nullptr; 
    } 
}; 
 
struct LinkedList{ 
private: 
    Node* head = nullptr; 
    Node* tail = nullptr; 
 
public: 
    void push(int val){ 
        Node * newNode = new Node(val); 
        if (head == nullptr){ 
            head = tail = newNode; 
        }else{ 
            tail -> next = newNode; 
            newNode -> prev = tail; 
            tail = newNode; 
        } 
    }
    void nearest_num(int k){
        Node * num = head;
        vector <int> v;
        int ind = -1;
        while(num != nullptr){
            v.push_back(abs(k-num->val));
            num = num -> next;

        }
        int min = 999999999;
        for(int i = 0; i < v.size(); i++){
            if(v[i] < min){
                min = v[i];
                ind = i;
            }
        }
        // cout <<endl;
        // for (int i = 0; i<v.size(); i++){
        //     cout << v[i] << " ";
        // }
        cout << ind;
        }
    };

int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list.push(x);
    }
    int k; cin >> k;
    list.nearest_num(k);
}