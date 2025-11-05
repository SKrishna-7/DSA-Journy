#include <iostream>
using namespace std;

// Pattern 4: Constant Row Number (or)
// Pattern 4: Right-Angled Number Pyramid - II
// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5

// In this pattern, we run the outer loop for N times as we have to print N rows, and since we have to print a right-angled triangle/pyramid which must be upright, so the inner loop will run for the row number in each iteration. 
// For eg: 1’s for row 1, 5’s 5 times for row 5, and so on. The only difference between this pattern and pattern 2 is that here we print numbers in each row instead of printing stars.

void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    pattern4(n);
    return 0;
}
