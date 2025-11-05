

// Pattern 1: Rectangular Star Pattern
// *****
// *****
// *****
// *****
// *****

// Approach: 
// There are 4 general rules for solving a pattern-based question: 

// - We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
// - Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
// - We print the ‘*’ inside the inner loop.
// - Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns.
// - In this particular problem, we run the outer loop for N times since we have N rows to be printed, the inner loop also runs for N times as we have to print N stars in each row. This way we get a rectangular star pattern (square) with an equal number of rows and columns.


#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    pattern1(n);
    return 0;
}
