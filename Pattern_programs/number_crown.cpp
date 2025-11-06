// Number Crown Pattern

// 1          1
// 12        21
// 12       321
// 1234    4321
// 12345  54321
// 123456654321


// In this problem, we want to print a combination of a numbered pyramid and a reverse-numbered pyramid. So, as per our observation in each row, numbers are printed from 1 to the row number and then some spaces and then again numbers from 1 to the row number but in reverse order.
// So, the outer loop will run from 1 to N and there will be three inner loops for numbers, spaces, and then again numbers. 

//The first inner loop will have numbers printed from 1 to the row number, the second will print the spaces ( 8 spaces in row 1, 6 spaces in row 2, and so on) and then the last loop will run from row number to 1 in decreasing manner. For spaces, we can say that initially, spaces are 2*(N-1) for Row 1 where N is the total no. of rows and then the spaces decrease by 2 in each iteration till the last row is reached.

#include <iostream>
using namespace std;

void pattern_12(int n){

    // int space=2*(n-1);
    int space=2*n-2;
    for(int i=1;i <=n;i++){

        //numbers

        for (int j=1 ;j<=i;j++){
            cout << j;
        }
        // spaces
        for(int j=0;j<space;j++){
            cout << ' ';
        }
        //numbers
        for (int j=i ;j>0;j--){
            cout << j;
        }
        space-=2;
        cout<<endl;
    }
}

int main(){

    int n=5;
    pattern_12(n);
    return 0;
}