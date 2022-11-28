#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};
class LinkedList{
public:
    Node * head;
    LinkedList(){
        head = nullptr;
    }
    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        } else {
            Node * i = head;
            while(i -> next != nullptr){
                i = i -> next;
            }
            i -> next = newNode;
        }
    }
    void print(){
        Node *i = head;
        while(i != nullptr){
            cout << i -> val << ' ';
            i = i -> next;
        }

    }
};

int main(){
    LinkedList list;
    int n; cin >> n;
    // while(n != 0){
    //     int x; cin >> x;
    //     if(n % 2 != 0){
    //         list.push(n);
    //     }
    //     n--;
    // }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i % 2 == 0){
           list.push(x);
        }
    }
    list.print();
//     student a("Tomiris", 18, 4.0);
//     cout << a.name;
}