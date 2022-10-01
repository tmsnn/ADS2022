// # from math import sqrt;
// # n = int(input())
// # l = []
// # i = 2
// # while(n >= 1):
// #     if n % i != 0:
// #         l.append(n)

#include <iostream>
using namespace std;
bool isPrime(int n)
        {
            int cnt = 0;
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    cnt = 1;
                    break;
                }
            }
            if (cnt == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
 
int main()
{
	int n, num=1;
    int count = 0;
    cin>>n;
        while (true)
            {
                num++;
                if(isPrime(num))
                {
                    count++;
                }
                if(count==n)
                {
                    cout<<num;
                    break;
               	}
}
	
}
 
