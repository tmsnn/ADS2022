#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
    
    node(int val){
        this -> val = val;
        next = prev = nullptr;
    }
};

struct LinkedList{
private:
    node * head = nullptr;
    node * tail = nullptr;
public:
    void add(int val){
        node * newNode = new node(val);
        if(tail == nullptr){
            tail = head = newNode;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void max_num(){
        int max = INT_MIN;
        node* cur = head;
        if(head == nullptr){
            cout << "error" << endl;
        } else {
        while(cur != nullptr){
            if(cur -> val > max){
                max = cur -> val;
            }
            cur = cur -> next;
        }
        cout << max << endl;
        }
    }
    
    void pop(){
        if(tail != nullptr){
            tail = tail -> prev;
            if(tail == nullptr){
                head = nullptr;
            } else {
                tail -> next = nullptr;
            }
        } else {
            head = nullptr;
            cout << "error" << endl;
        }
    }

    void getcur(){
        if(tail == nullptr){
            cout << "error" << endl;
        } else {
            cout << tail -> val << endl;
        }
    }
};

int main(){
    LinkedList list;
    int n; cin >> n;
    string s; int x;
    while(n--){
        cin >> s;
        if(s == "add"){
            cin >> x;
            list.add(x);
        }
        if(s == "delete"){
            list.pop();
        }
        if(s == "getmax"){
            list.max_num();
        }
        if(s == "getcur"){
            list.getcur();
        }
    }
}