#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node * next;
    Node* prev; 
    Node(int val){
        this -> val = val;
        next = nullptr;
        prev = nullptr; 
    }
};
struct LinkedList{ 
private: 
    Node* head = nullptr; 
    Node* tail = nullptr; 
public:
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

     void insert(int val, int pos){
        int i = 1;
        Node * cur = head;
        if(pos == 0){
        Node * newNode = new Node(val);
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
            }
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        } else {
            Node * cur = head;
            while(cur != nullptr){
                if(i == pos){
                    newNode -> next = cur -> next;
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
                i++;
            }
        }
        
    } 
    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << ' ';
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList list;
    int n; cin >> n;
    while(n > 0){
        int x; cin >> x;
        list.push(x);
        n--;
    }
    int k; cin >> k;
    int ind; cin >> ind;
    list.insert(k, ind);
    list.print();
}