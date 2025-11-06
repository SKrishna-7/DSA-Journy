// Hollow Rectangle Pattern

// ******
// *    *
// *    *
// *    *
// *    *
// ******

//This problem is a very simple one where we just have to print a hollow rectangle. So, after observation, we see that the stars are only printed at the border of the rectangle, and on the rest of the positions, spaces are printed. Hence, the outer loop and inner loop both will loop for n times and in the inner loop we add a condition that if the row index or column index is equal to 0 or n-1, then stars should get printed otherwise spaces should be printed.




#include <iostream>

using namespace std;



void pattern21(int n){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){

            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;

    }
}
int main()
{   
    int n=5;
    
    pattern21(n);

    return 0;
}