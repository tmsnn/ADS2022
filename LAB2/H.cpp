#include <bits/stdc++.h> 
using namespace std; 
 
struct Node{ 
    int val; 
    int index; 
    Node * next; 
    Node * prev; 
     
    Node(int val){ 
        this -> val = val; 
        next = nullptr; 
        prev = nullptr; 
    } 
}; 
 
class LinkedList{ 
    Node* head; 
    Node* tail; 
public: 
    LinkedList(){ 
        head = nullptr; 
        tail=nullptr; 
    }  
 
    void push(int val, int pos){ 
        Node * newNode = new Node(val); 
        if (pos == 0){ 
            newNode->next=head; 
            head=newNode; 
        } else { 
            Node* cur = head; 
            int i = 1; 
            while(cur!=nullptr){ 
                if(i==pos){ 
                    newNode->next = cur->next; 
                    cur->next=newNode; 
                    break; 
                } 
                cur=cur->next; 
                i++; 
            } 
        } 
    } 
 
    void del(int pos){ 
        if (pos == 0) { 
            head = head->next; 
        } else{ 
            Node * cur = head; 
            Node * prev = nullptr; 
            int i = 0; 
            while (cur != nullptr){ 
                if (i == pos) { 
                    prev->next = cur->next; 
                    delete cur; 
                    break; 
                } 
                prev = cur; 
                cur = cur -> next; 
                i++; 
            } 
        } 
    } 
     
     
    void print(){ 
    Node * cur = head; 
    if (head == nullptr){ 
        cout << -1 << endl; 
    } 
    while(cur != nullptr){ 
        cout << cur -> val << " "; 
        cur = cur->next; 
    } 
    cout << endl; 
    } 
 
    void replace(int p1,int p2){ 
        int i = 0; 
        Node * cur = head; 
        int val; 
        while (cur != nullptr){ 
            if (i == p1){ 
                val = cur->val; 
                break; 
            } 
            cur = cur->next; 
            i++; 
        } 
        del(p1); 
        push(val, p2); 
    } 
 
    void reverse(){ 
        Node * cur = head; 
        Node * prev = nullptr; 
        Node * next = nullptr; 
        while (cur != nullptr){ 
            next = cur-> next;  
            cur->next = prev; 
            prev = cur; 
            cur = next; 
        } 
        head = prev; 
        tail = next; 
    } 
 
    void cyclic_left(int x){ 
        if ( x == 0) return; 
        else { 
            int  i = 0; 
            Node * start = head; 
            Node * cur = head; 
            Node * prev = nullptr; 
            while (cur != nullptr){ 
                if (i < x ){ 
                    prev = start; 
                    start = start->next; 
                } 
                if (cur->next == nullptr){ 
                    break; 
                } 
                cur = cur->next; 
                i++; 
            } 
            prev->next = nullptr; 
            cur->next = head; 
            head = start; 
        } 
    } 
 
    void cyclic_right(int x){ 
        if (x == 0) return; 
        int size = 0; 
        int k = 0; 
        int i; 
        Node * cur = head; 
        while (cur != nullptr){ 
            if (cur->next == nullptr) break; 
            cur = cur->next; 
            size++; 
        } 
        k = size - x + 1; 
        cyclic_left(k); 
    } 
 
}; 
 
int main () { 
    LinkedList list; 
    int n; 
     
    while (cin >> n){ 
        if (n == 0) return 0; 
        else if (n == 1) { 
            int x, pos; 
            cin >> x >> pos; 
            list.push(x, pos); 
        } else if (n == 2) { 
            int x; cin >> x; 
            list.del(x); 
        } else if (n == 3) { 
            list.print(); 
        } else if (n == 4) { 
            int p1, p2; 
            cin >> p1 >> p2; 
            list.replace(p1, p2); 
        } else if (n == 5) { 
            list.reverse(); 
        } else if (n == 6) { 
            int x; cin >> x; 
            list.cyclic_left(x); 
        } else if (n == 7){ 
            int x; cin >> x; 
            list.cyclic_right(x); 
        } 
    } 
}