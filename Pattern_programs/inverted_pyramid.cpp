#include <iostream>
using namespace std;

// Pattern 8: Inverted Pyramid
// *********
//  *******
//   *****
//    ***
//     *

// Approach
// In this particular pattern, we run the outer loop for N times as we have to print N rows as usual. Now, the question arises what will be the logic behind the inner loop?

// Similar to the last pattern, we can clearly observe that for each row there are some spaces that get printed then some stars, and then again some spaces giving it an inverse pyramidal look. For eg: In the first row (i=0) there are 0 spaces, 9 stars, then again 0 spaces. In the second row (i=1) there is 1 space, 7 stars, then again 1 space so we can say that there are i spaces, 2*N - (2*i+1) stars, and then again i space for each row where i is the row index. We thus simply run 3 inner loops, first for printing the spaces, then the stars, and then the spaces again.

void pattern8(int n) {
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < i; space++)
            cout << " ";
        for (int star = 0; star < 2 * n - (2 * i + 1); star++)
            cout << "*";
        cout << endl;
    }
}

int main() {
    int n = 5;
    pattern8(n);
    return 0;
}
