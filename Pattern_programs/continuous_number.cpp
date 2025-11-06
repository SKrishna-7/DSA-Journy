// Increasing Number Triangle Pattern

// 1
// 2  3
// 4  5  6
// 7  8  9  10
// 11  12  13  14  15
// 16  17  18  19  20  21

// Approach
// In this problem, we just have to print the right-angled number pyramid but here, we also have to increase the number each time we print it. For printing, the right-angled pyramid as we know the outer loop runs for N times and the inner loop runs for i times. Now, to print an increasing number pyramid we just have to increment the number inside the inner loop so that after printing the number each time it increases by 1.



#include <iostream>
using namespace std;

void pattern_13(int n){
    int c=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
        {
            cout<<c<<' ';
            c+=1;
        }
        cout<<endl;
    }
}
int main() {
    int n = 5;
    pattern_13(n);
    return 0;
}
