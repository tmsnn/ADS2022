#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    Node * next;
    Node * prev;
    Node(string val){
        this -> val = val;
        next = nullptr;
        prev = nullptr;
    }
};
class LinkedList{
private:
    Node * head = nullptr;
    Node * tail = nullptr;
public:
    void push(string val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void rotate(int x){
        int cnt = 0;
        if(x == 0) return;
        Node * cur = head;
        while(cnt != x){
            cnt++;
            tail -> next = head;
            tail = head;
            head = head -> next;
            tail -> next = nullptr;
        }
    }
    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    int n, x; cin >> n;
    cin >> x;
    LinkedList list;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        list.push(s);
    }
    list.rotate(x);
    list.print();
}