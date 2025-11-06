//  Alpha-Triangle Pattern


// E 
// D E 
// C D E 
// B C D E 
// A B C D E 

// #Approach

// In this problem, we have to print an alpha triangle as shown in the examples above. We observe from the examples that each row ends with the letter E in the case when N = 5 ( ‘A’ + 4 ). Also the triangle has to be right-angled so like the previous patterns, the outer loop will run for N times and the inner loop for i times. In the inner loop, we’ll start from the letter that comes i before the (‘A’ + N -1)th letter and then run the loop till we reach (‘A’ + N-1) in every row. For example, for N = 5 in each row, the letters will be printed from ‘E’ - i to ‘E’ where i is the row index.



#include <iostream>
using namespace std;




void pattern18_1(int n){
    for(int i=0;i<n;i++){
        char ch ='E'-i;
        for(int j=0;j<=i;j++)
        {
            cout<<ch<<' ';
            ch++;
        }
        cout<<endl;
    }
}



void pattern18_2(int n){
    for(int i=0;i<n;i++){
        char ch ='E'- i;
        for(char j=ch;j<='E';j++)
        {
            cout<<ch<<' ';
            ch++;
        }
        cout<<endl;
    }
}


int main() {
    int n = 5;
    // pattern18_1(n);
    pattern18_2(n);
    return 0;
}
