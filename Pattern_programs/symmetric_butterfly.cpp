// Symmetric-Butterfly Pattern

// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *

// In this problem, we have to print a butterfly-like star pattern. This pattern is very similar to Pattern 10 in this series as here we can see that for Row 1 we have 2 stars, and 8 spaces, and for Row 2 we have 4 stars and 6 spaces, and so on. Also, after the nth row, the stars decrease and the spaces increase. So, the outer loop will run for 2*n -1 times ( n times when spaces > stars and then n-1 when stars > spaces ). There will be 3 inner loops, one to print stars, then spaces, and then again stars. Spaces will decrement by 2 as i increases and when i reaches n, then spaces decrement by 2 every time we enter a new row. When i<n, the stars printed in each row are 2*i, and as soon as i>n, the stars in each row would be twice of 2*n-i.


#include <iostream>

using namespace std;



void pattern20(int n){
    int space=2*n -2;
    int i,j;
    for(i=1;i<=2*n-1;i++){

        int star=i;
        
        if(i > n) star = 2*n - i ;
        for(j=0;j<star;j++){
            cout<<'*';
        }
        
        for(j=1;j<=space;j++){
            cout<<' ';
        }
        
        for(j=0;j<star;j++){
            cout<<'*';
        }
        if(i < n) space-=2;
        else space+=2;

        cout<<endl;

    }
}
int main()
{   
    int n=5;
    
    pattern20(n);

    return 0;
}