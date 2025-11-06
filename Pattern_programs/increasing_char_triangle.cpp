// Increasing Letter Triangle Pattern

// A
// A B
// A B C
// A B C D
// A B C D E
// A B C D E F

// Approach
// In this pattern problem, instead of numbers, we have to print alphabets hence making the pattern look like a right-angled triangle. So, the outer loop will run for N rows and the inner loop will loop for i alphabets in each row where i is the row number. Alphabets in each row will start from A each time we enter a new row and will loop till (A+i)th alphabet in that row.



#include <iostream>
using namespace std;

void pattern_14(int n){

    for(int i=1;i<=n;i++){
        for(char j='A';j<'A'+i;j++)
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int n = 5;
    pattern_14(n);
    return 0;
}
