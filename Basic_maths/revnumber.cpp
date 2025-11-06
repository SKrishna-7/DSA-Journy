#include<iostream>
#include<math.h>

using namespace std;


int main(){

    // int n=111;
    int n=-121;
    int rev=0;
    while(n !=0){

        int last = n%10;
        
        rev=(rev*10)+last;

        n/=10;
    }

    cout <<"Rev : " << rev <<endl;

  
    return 0;
}