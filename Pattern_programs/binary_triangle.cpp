// **Binary Triangle (Alternating 1 and 0)**  

// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1


//Approach

// In this problem, we have to print binary digits alternatively in each row and column as shown in the examples. Let’s say that the first row starts with the binary digit ‘1’, the second row must start with ‘0’ and then the 3rd row with ‘1’ again, and so on. 
// Similar is the case for the columns as well. Initially, we declare a start variable and set it to 1 for the first row. For even no. of rows, the start variable is 1 and for odd it is 0. Now for the inner loop, the numbers are printed i times (i is the row index) alternatively by simply subtracting the start variable from 1 after each iteration.

#include<iostream>
using namespace std;

void pattern_11(int n){

    int start=1;
    for(int i=1;i<=n;i++){
        if (i%2 == 0) start=0;
        else start=1;
        
        for(int j=1;j<=i;j++){
            cout<< start <<" ";

            start=1-start;
        }
        cout<<endl;
    }
}


int main(){

    int n=5;
    pattern_11(n);
    return 0;
}