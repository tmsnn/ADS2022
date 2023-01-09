#include <bits/stdc++.h>
using namespace std;


class heap{
    int arr[100258];
    int size;
    public:
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

    void push(int x){
        arr[size] = x;
        size++;
        up(size - 1);
    }

    int up(int i){
        while(i > 0 && arr[i] > arr[super(i)]){
            swap(arr[i], arr[super(i)]);
            i = super(i);
        }
        return i + 1;
    }

    void res(int i, int x){
        arr[i] += x;
        cout << up(i) << endl;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    int n; cin >> n;
    heap hp;
    while(n--){
        int x; cin >> x;
        hp.push(x);
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int x, z;
        cin >> x >> z;
        hp.res(x - 1, z);
    }

    hp.print();
}