#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;


void divisor(int n){
    
    vector<int> list;

    for(int i=1;i<=sqrt(n);i++){

        if( n % i == 0){
            list.push_back(i);
            // cout<<"Divisor : " << i << endl;
            if(i!=n/i){
                // cout<<"Divisor : " << n/i << endl;
                list.push_back(n/i);
            }
        }
    }

    sort(list.begin(),list.end());

    for(auto l:list){
        
        cout<<"Divisors : " << l  << endl;
    }

    
}

int main(){

    int n=36;
    // int c=0;
    // for(int i=1;i<=36;i++){

    //     if( n % i == 0){

    //         cout<<"Divisor : " << i << endl;
    //         c++;
    //     }
    // }

    // cout<<c;
    

    divisor(n);
    return 0;
}