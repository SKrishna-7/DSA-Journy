#include<iostream>
using namespace std;

void factorial_parametarized(int n,int sum){

    if (n==0) {
        cout<<sum;
        return;
    }

    sum*=n;
  
    factorial_parametarized(n-1,sum);
    
}
int factorial_functional(int n){

    if (n==0) {
        return 1;
    }

    return n * factorial_functional(n-1);
}



int main(){

    int n=5;

    // sumofN(n,0);  // parameterized

//    factorial_parametarized(n,1);
    cout<< factorial_functional(n);

    return 0;
}