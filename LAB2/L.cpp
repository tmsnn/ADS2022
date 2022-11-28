# include <bits/stdc++.h> 
using namespace std; 

struct Node{ 
   int val; 
   Node * next; 
   Node(int val){ 
    this ->val = val; 
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
        if (head == nullptr){ 
            head  = newNode; 
        } else { 
            Node * i = head; 
            while (i->next != nullptr){ 
                i = i->next; 
            } 
            i->next = newNode; 
        } 
    } 
 
    int findMaxSum(){ 
        int sum = 0; 
        Node * cur = head; 
        int mx = -999999; 
        while (cur != nullptr){ 
            sum += cur->val; 
            if (sum < cur->val){ 
                sum = cur->val; 
            } 
            mx = max(sum, mx); 
            cur = cur->next; 
        } 
        return mx; 
    } 
}; 
  
int main(){ 
    int n; 
    cin >> n; 
    LinkedList list; 
    for (int  i = 1; i <= n; ++i){ 
        int x; cin >> x; 
        list.push(x); 
    } 
    cout << list.findMaxSum(); 
}