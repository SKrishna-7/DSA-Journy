#include <iostream>
using namespace std;

// Pattern 9: Diamond
//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *

// This pattern is just a mixture of the last two patterns ( erect pyramid and inverted pyramid). Firstly, we will print the erect pyramid and then an inverted pyramid below it.


void pattern7(int n);
void pattern8(int n);

void pattern9(int n) {
    pattern7(n);
    pattern8(n);
}

void pattern7(int n) {
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++)
            cout << " ";
        for (int star = 0; star < 2 * i + 1; star++)
            cout << "*";
        cout << endl;
    }
}

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
    pattern9(n);
    return 0;
}
