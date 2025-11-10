#include<iostream>
using namespace std;

void sumofN(int n,int sum){

    if (n<0) {
        cout<<sum;
        return;
    }

    sum+=n;
  
    sumofN(n-1,sum);
    
}
int sumofN_functional(int n){

    if (n<0) {
        return 0;
    }

    return n + sumofN_functional(n-1);
}

//Also use     int sum = N * (N + 1) / 2;


int main(){

    int n=5;

    // sumofN(n,0);  // parameterized

    cout << sumofN_functional(n);

    return 0;
}