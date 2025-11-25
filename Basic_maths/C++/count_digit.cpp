#include<iostream>
#include<math.h>

using namespace std;


int main(){

    int n=4531455;
    int sum=0;
    int count=0;
    while(n > 0){

        int last = n%10;
        count++;
        sum+=last;
        cout << last << endl;
        
        n=n/10;
    }

    cout <<"Sum : " << sum;
    cout <<"\nCount : " << count <<endl;

    //count approach-2
    int n1=4531455;
    int count_digit= (int)(log10(n1)+1);
    cout<<count_digit;
    return 0;
}