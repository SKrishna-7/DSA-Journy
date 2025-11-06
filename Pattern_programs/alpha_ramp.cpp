#include <iostream>
using namespace std;

// Alpha-Ramp Pattern
// A 
// B B
// C C C
// D D D D
// E E E E E
// F F F F F F

// #Approach
// In this pattern problem, as we can observe we have to print a right-angled pyramid just like our last pattern but with a twist. Here, in every row, we have to print the same character i times where i is the row number. For example, the 1st row will print 1 A, the 2nd row will print 2 B’s, and so on. So, similar to the previous patterns the outer loop will loop for N times and the inner loop for i times with the character value incrementing each time we enter a new row.




void pattern16(int n){
    for(int i=0;i<n;i++){
        char ch ='A'+i;
        for(int j=0;j<=i;j++)
        {
            cout<<ch<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int n = 5;
    pattern16(n);
    return 0;
}
