#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int a[100289];
    int size;

    heap(){
        size = 0;
    }
    
    int super(int i){
        return (i - 1) / 2;
    }

    int left_child(int i){
        return (i * 2) + 1;
    }

    int right_child(int i){
        return (i * 2) + 2;
    }

    void up(int i){
        while(i > 0 && a[i] > a[super(i)]){
            swap(a[i], a[super(i)]);
            i = super(i);
        }
    }

    void push(int x){
        a[size] = x;
        size++;
        up(size - 1);
    }

    void check(){
        int cnt = 0;
        for(int i = 0; i <= size / 2 + 1; i++){
            if(left_child(i) < size && right_child(i) < size){
                if(a[left_child(i)] < a[right_child(i)]){
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
};


int main(){
    int n; cin >> n;
    heap hp;
    while(n--){
        int x; cin >> x;
        hp.push(x);
    }
    hp.check();
}