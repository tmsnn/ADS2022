#include <bits/stdc++.h> 
using namespace std; 
 
struct Node{ 
    char val; 
    int cnt; 
    Node * next; 
    Node * prev; 
       
    Node(char val){ 
        this -> val = val; 
        next = nullptr; 
        prev = nullptr; 
    } 
}; 
 
class LinkedList{ 
    Node * head; 
public: 
    LinkedList(){ 
        head = nullptr; 
    }  
 
    void push(char val){ 
        Node * newNode = new Node(val); 
        if (head == nullptr){ 
            head = newNode; 
        } else { 
            Node * cur = head; 
            while (cur != nullptr){ 
                if (cur -> next == nullptr){ 
                    cur -> next = newNode; 
                    break; 
                } 
                cur = cur -> next; 
            }  
        } 
    } 
    void solve(vector <int> v){ 
        while (head != nullptr and v[head->val - 'a'] > 1){ 
            head = head -> next; 
        }  
        if (head == nullptr){ 
            cout << -1 << " "; 
        } else { 
            cout << head->val << " "; 
        } 
    } 
 
}; 
 
int main (){ 
    int n; cin >> n; 
    for (int i = 0; i < n; i++){ 
    vector <int> v(30, 0); 
        int m; cin >> m; 
        LinkedList list; 
        for (int j = 0; j < m; j++){ 
            char c; cin >> c; 
            v[c -'a']++; 
            list.push(c); 
            list.solve(v); 
        } 
        cout << endl; 
    } 
}