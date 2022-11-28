#include <bits/stdc++.h> 
using namespace std; 
 
struct Node{ 
    string s; 
    Node * next; 
    Node * prev; 
 
    Node(string s){ 
        this->s = s; 
        next = NULL;  
        prev = NULL; 
    } 
}; 
 
 
class LinkedList{ 
public: 
    Node * head; 
    Node * tail; 
    int size; 
 
    LinkedList(){ 
        head = NULL; 
        tail = NULL; 
    } 
 
    void add_front(string s){ 
        Node * newNode = new Node(s); 
        if (head == nullptr){ 
            head = tail = newNode; 
        }else{ 
            head -> prev = newNode; 
            newNode -> next = head; 
            head = newNode; 
        } 
        cout << "ok" << endl; 
    } 
     
    void add_back (string s){ 
        Node * newNode = new Node(s); 
        if (tail == nullptr){ 
            tail = head = newNode; 
        } else { 
            tail -> next = newNode; 
            newNode -> prev = tail; 
            tail = newNode; 
        } 
        cout << "ok" << endl; 
    } 
 
    void erase_front () { 
        if (head != nullptr){ 
            cout << head -> s <<endl; 
            head = head -> next; 
            if (head == nullptr){ 
            tail = nullptr; 
            } else { 
                head -> prev = nullptr; 
            } 
        } else { 
            tail = nullptr; 
            cout << "error" << endl; 
        } 
    } 
 
    void erase_back(){ 
        if (tail != nullptr){ 
            cout << tail -> s << endl; 
            tail = tail -> prev; 
            if (tail == nullptr) { 
                head = nullptr; 
            } else { 
                tail -> next = nullptr; 
            } 
        } else { 
            head = nullptr; 
            cout << "error" << endl; 
        } 
    } 
 
    void front(){ 
        if (head != nullptr){ 
            cout << head-> s << endl; 
        } else { 
            cout << "error" << endl; 
        } 
    } 
     
    void back(){ 
        if (tail != nullptr){ 
            cout << tail->s << endl; 
        } else cout << "error" << endl; 
    } 
 
    void clear(){ 
        head = nullptr; 
        tail = nullptr; 
        cout << "ok" << endl; 
    } 
}; 
 
int main () { 
    LinkedList list; 
    string s; 
    while (cin >> s){ 
        if (s == "add_front"){ 
            string t; cin >> t; 
            list.add_front(t); 
        } else if (s == "add_back"){ 
            string t; cin >> t;  
            list.add_back(t); 
        } else if (s == "erase_front"){ 
            list.erase_front(); 
        } else if (s == "erase_back"){ 
            list.erase_front(); 
        } else if (s == "back"){ 
            list.back(); 
        } else if (s == "front"){ 
            list.front(); 
        }else if (s == "clear"){ 
            list.clear(); 
        } else if (s == "exit"){ 
            cout << "goodbye" << endl; 
            return 0;  
        } 
    } 
}