#include<iostream>
#include<math.h>

using namespace std;


int main(){

    // int n=111; // 1^3 + 1^3 + 1^3 = 3

    int n=371;
    int dup=n;
    int sum=0;
    while(n > 0){

        int last = n%10;
        
        sum=sum+(last*last*last);

        n=n/10;
    }

    cout <<"Armstrong sum : " << sum <<endl;

    if (sum==dup) cout<<"Armstrong";
    else cout<<"Not Armstrong";
  
    return 0;
}