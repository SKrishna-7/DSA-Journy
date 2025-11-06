// Symmetric-Void Pattern

// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *
// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************

// Contrary to the previous patterns, this pattern observes symmetry. We can clearly see that the first half of the pattern is just a mirror image of the second half of the pattern. If we observe the first part, we see that like some previous patterns, it can also be divided into 3 parts i.e. stars, spaces, and then stars. In the first row, there are no spaces and 10 stars, in the second row, there are 2 spaces and 8 stars, and so on. So, we initialize the spaces with 0 initially which will eventually increment by 2 whenever we enter a new row. The stars, however, will be twice the row number, half of the stars would be printed before the spaces and half after the spaces.

// Similar will be the case of the second half of the pattern too. The initial number of spaces would be equal to 2*(N-1) and 1 star each would be printed on either side of the spaces initially. The spaces will decrease by 2 and the stars will increase by 2 in each row."



#include<iostream>
using namespace std;


void pattern19(int n){

    int i,j;
    int space=0;
    for(i=1;i<=n;i++){

        //star

        for(j=1;j<=n-i+1;j++){
            cout<<'*';
        }
        //space
        for(j=1;j<space+1;j++){
            cout<<' ';
        }

        //star
         for(j=1;j<=n-i+1;j++){
            cout<<'*';
        }

        cout<<endl;
        space+=2;
    }
    int space1=8;
    for(i=1;i<=n;i++){

        //star

        for(j=1;j<=i;j++){
            cout<<'*';
        }
        //space
        for(j=0;j<space1;j++){
            cout<<' ';
        }

        //star
         for(j=1;j<=i;j++){
            cout<<'*';
        }

        cout<<endl;
        space1-=2;
    }

}

int main(){

    int n=5;
    pattern19(n);
    return 0;
}