void push(int val){ 
        Node * newNode = new Node(val); 
        if (head == nullptr){ 
            head = newNode; 
        }else { 
            Node *cur = head; 
            while(cur != nullptr){ 
                if (cur -> val == val){ 
                    cur->cnt++; 
                } else if (cur ->next == nullptr){ 
                    cur ->next = newNode; 
                    break; 
                } 
                cur = cur -> next; 
            } 
        } 
    } 
 
    int mx_cnt(){ 
        Node * cur = head; 
        int mx = 1; 
        while(cur != nullptr){ 
            if (cur->cnt > mx) { 
                mx = cur->cnt;  
            } 
            cur = cur->next; 
        } 
        return mx; 
    } 
 
    void count1(){ 
        vector <int> v; 
        Node * cur = head; 
        while (cur != nullptr){ 
            if(cur->cnt == mx_cnt()){ 
                v.push_back(cur->val); 
            } 
            cur = cur -> next; 
        } 
        sort (v.rbegin(), v.rend()); 
        for(int i = 0; i < v.size(); i++){ 
            cout << v[i] << " ";  
        } 
    }