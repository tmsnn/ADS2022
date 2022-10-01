#include <iostream>  
using namespace std;  
int main()  
{  
  int n, flag = 0;  
  cin >> n;  
  if(n == 1){
    cout << "NO";
  }  else {
  for(int i = 2; i <= n / 2; i++)  
  {  
      if(n % i == 0)  
      {  
          cout<< "NO";  
          flag = 1;  
          break;  
      }  
  }  
  if (flag == 0){  
      cout << "YES";  
  return 0; 
  } 
}
}  
