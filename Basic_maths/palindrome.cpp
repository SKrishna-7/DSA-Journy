#include<iostream>
#include<math.h>

using namespace std;


int main(){

    // int n=123;
    int n=120;
    int dup=n;
    int rev=0;

    if (n<=0 || n%10 == 0){
        cout<<"Not Palindrome";
    }
    else{

        while(n !=0){
            
            int last = n%10;
            
            rev=(rev*10)+last;
            
            n/=10;
        }
        
        cout <<"Rev : " << rev <<endl;
        
        if (rev==dup) cout<<"Palindrome";
        else cout<<"Not Palindrome";
    }
  
    return 0;
}