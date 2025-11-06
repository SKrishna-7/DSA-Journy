#include <iostream>
using namespace std;

// Alpha-Hill Pattern

//      A     
//     ABA    
//    ABCBA   
//   ABCDCBA  
//  ABCDEDCBA 
// ABCDEFEDCBA

// #Approach

// In this problem, we have to print an alphabet triangle as shown in the examples above where we can clearly observe that the first row has only the letter A in the middle and some spaces on either side of it and the second row has the letters ABA and some spaces again on both sides. So, we observe from this that first there are some spaces, then letters increasing from A to A + i where i is the row number and then decreasing back to A, then finally some more spaces to the end. Hence, like all the previous patterns the outer loop will loop for N times and there will be three inner loops in this pattern.


// The first inner loop is for printing the (N-i-1) spaces ( 1st row -> 4 spaces, 2nd row -> 3 spaces, and so on), the second one for printing the characters, and then the last one again for printing the spaces. For the character loop, we define the breakpoint till where the character must increase and after that, it must decrease. The breakpoint can be defined by (2*i+1)/2 for each row.



void pattern17(int n){
   for(int i =0 ; i<n ; i++){
        
        char ch='A';
        int breakpoint=(2*i+1) / 2;
        for(int space_1=0;space_1 < n-i-1;space_1++){
            cout << ' ';
        }
       
            for(int star=1;star <= 2*i+1;star++){
            cout<<ch;
            if(star <= breakpoint) ch++;
            else ch--;
        
        }
        
        // for(int space_2=0;space_2<n-i-1;space_2++){
        //     cout << " ";
        // }
        cout<<endl;
}
}
int main() {
    int n = 5;
    pattern17(n);
    return 0;
}
