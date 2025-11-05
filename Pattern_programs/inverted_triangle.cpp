#include <iostream>
using namespace std;

// Pattern 5: Inverted Right Triangle
// * * * * *
// * * * *
// * * *
// * *
// *

// Approach
//In this pattern, we run the outer loop for N times as we have to print N rows and since we have to print a right-angled triangle/pyramid which must be inverted, the inner loop will run in decreasing order of stars
//for eg: Row 1 (i=0) would contain N stars, Row 2 (i=1) would contain (N -1) stars and so on.


void pattern5_1(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}


void pattern5_2(int n){

    // for(int i=0 ; i<=n ; i++){
    //     for(int j=(n-i)-1;j>=0;j--){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0 ; i<=n ; i++){
        for(int j=1;j<=(n-i)+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}


int main() {
    int n = 5;
    pattern5_2(n);
    return 0;
}
