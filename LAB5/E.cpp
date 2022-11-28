#include <bits/stdc++.h>
using namespace std;

long long summ = 0;
struct MinHeap{
    long long size = 0;
    long long a[100000];

    long long root(long long index){
        return (index - 1) / 2; 
    }
    long long left(long long index){
        return (2 * index) + 1;
    }
    long long right(long long index){
        return (2 * index)  + 2;
    }

    void push_down(long long index){
        long long min_ind = index;
        long long l = left(index);
        long long r = right(index);
        
        if(l < size && a[min_ind] > a[l]){
            min_ind = l;
        }

        if(r < size && a[min_ind] > a[r]){
            min_ind = r;
        }

        if(min_ind != index){
            swap(a[min_ind], a[index]);
            push_down(min_ind);
        }
    }
    void add(long long value){
        summ += value;
        long long index = size;
        a[index] = value;
        size++;

        long long p = root(index);

        while(index != 0 && a[index] < a[p]){
            swap(a[index], a[p]);
            index = p;
            p = root(index);
        }
    }
};

int main(){
    int q, k;
    cin >> q >> k;
    MinHeap heap;
    string s;
    
    int cnt = 0;
    while(cnt < q){
        cin >> s;
        cnt++;
        int x;
        if(s == "insert"){
            cin >> x;
            if(heap.size == k){
                if(heap.a[0] < x){
                    summ += (x - heap.a[0]);
                    heap.a[0] = x;
                    heap.push_down(0);
                }
            }
            else{
                heap.add(x);
            }
        }
        else if(s == "print"){
            cout << summ << endl;
        }
    } 
}