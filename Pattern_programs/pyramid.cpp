#include <iostream>
using namespace std;

// Pattern 7: Pyramid
//     *
//    ***
//   *****
//  *******
// *********


// #Approach
// In this particular pattern, we run the outer loop for N times as we have to print N rows as usual. Now, the question arises what will be the logic behind the inner loop?
// As we can clearly observe that for each row there are some spaces that get printed then some stars and then again some spaces giving it a final pyramidal look. For eg: In the first row (i=0) there are 4 spaces, 1 star, then again 4 spaces. In the second row (i=1) there are 3 spaces, 3 stars, then again 3 spaces so we can say that there are N-i-1 spaces, 2*i+1 stars, and then again N-i-1 spaces for each row where i is the row index. We thus simply run 3 inner loops first for printing the spaces, then the stars, and then the spaces again.



void pattern7(int n) {
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++)
            cout << " ";
        for (int star = 0; star < 2 * i + 1; star++)
            cout << "*";
        cout << endl;
    }
}

int main() {
    int n = 5;
    pattern7(n);
    return 0;
}
