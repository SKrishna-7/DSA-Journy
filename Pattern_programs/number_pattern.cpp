// The Number Pattern



// 6 6 6 6 6 6 6 6 6 6 6 
// 6 5 5 5 5 5 5 5 5 5 6 
// 6 5 4 4 4 4 4 4 4 5 6 
// 6 5 4 3 3 3 3 3 4 5 6 
// 6 5 4 3 2 2 2 3 4 5 6 
// 6 5 4 3 2 1 2 3 4 5 6 
// 6 5 4 3 2 2 2 3 4 5 6 
// 6 5 4 3 3 3 3 3 4 5 6 
// 6 5 4 4 4 4 4 4 4 5 6 
// 6 5 5 5 5 5 5 5 5 5 6 
// 6 6 6 6 6 6 6 6 6 6 6

// This problem is not generally asked in the interviews but it is good to practice such problems for the sake of logic building. So, what we can observe from the above examples is that on the perimeter of the square, there is an integer no. N which decreases by 1 as we move inside the square level-wise. Since this cannot be printed directly, we print it in reverse fashion (0’s at the border of the square, then 1 in the inner perimeter, then 2, and so on ) and then subtract the whole pattern by N at the end which just makes the outermost perimeter filled with the number N, inner perimeter with N-1 and finally the centermost element with the integer 1. The outer and the inner loop will run for the same number of times ( since we have to print square) i.e, 2*N-1 times and the inner loop would print the numbers based on the logic as described below ( for N = 4 )


// As per the above illustration, we take the minimum distance of the current cell from each of the ends of the square ( min(1,3,3,5) ) and make the current cell value equal to that number. 

/* 

The distance of the current cell from the top can be written as the row number i.e, i.
The distance of the current cell from the left can be written as the column number i.e, j.
The distance of the current cell from the right can be written as (2*n-2) - j.
The distance of the current cell from the bottom can be written as (2*n-2) - i.

*/


#include <iostream>

using namespace std;


#include <math.h>

void pattern22(int n){
    int i,j;
    int num=1;
    int size=2*n-1;
    for(i=0;i<n*2-1;i++){
        
        for(j=0;j<n*2-1;j++){
            
            int top=i;
            int left=j;
            int right=size - 1 - i;
            int bottom=size - 1 - j;

            int d=min(min(top,left),min(bottom,right));


            cout << (n-d) << ' ';
    }

        cout<<endl;
}

}


int main()
{   
    int n=5;
    
    pattern22(n);

    return 0;
}