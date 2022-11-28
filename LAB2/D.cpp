#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    int cnt = 1;
    Node * next;
    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};
class LinkedList{
public:
Node * head;
int cnt = 1;
LinkedList(){
    head = nullptr;
}
void push(int val){ 
        Node * newNode = new Node(val); 
        if (head == nullptr){ 
            head = newNode; 
        }else { 
            Node *cur = head; 
            while(cur != nullptr){ 
                if (cur -> val == val){ 
                    cur -> cnt++; 
                } else if (cur -> next == nullptr){ 
                    cur -> next = newNode; 
                    break; 
                } 
                cur = cur -> next; 
            } 
        } 
    }
int max_cnt(){ 
        Node * cur = head; 
        int mx = 1; 
        while(cur != nullptr){ 
            if (cur-> cnt > mx) { 
                mx = cur -> cnt;  
            } 
            cur = cur->next; 
        } 
        return mx; 
    }
void print(){ 
        vector <int> v; 
        Node * cur = head; 
        while (cur != nullptr){ 
            if(cur->cnt == max_cnt()){ 
                v.push_back(cur->val); 
            } 
            cur = cur -> next; 
        } 
        sort (v.rbegin(), v.rend()); 
        for(int i = 0; i < v.size(); i++){ 
            cout << v[i] << " ";  
        } 
    }
};
int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        list.push(m);
    }
    list.print();
}