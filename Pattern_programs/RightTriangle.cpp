#include <iostream>
using namespace std;

// Pattern 2: Right Triangle
// *
// * *
// * * *
// * * * *
// * * * * *

// Approach: 

// There are 4 general rules for solving a pattern-based question : 

// -  We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
// - Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
// - We print the ‘*’ inside the inner loop.
// - Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns or not.
// - In this problem, we run the outer loop for N times as we have to print N rows, and since we have to print a right-angled triangle/pyramid which must be upright, the inner loop will run for the row number in each iteration. 
// For eg: 1 star for row 1, 5 stars for row 5, and so on.


void pattern2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    pattern2(n);
    return 0;
}
