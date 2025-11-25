#include<iostream>

using namespace std;


void prime(int n){
        int c=0;

        for(int i=1;i<=n;i++){
            
            if(n%i == 0){
                c++;
            }
        }
        if(c==2){
                cout<<"Prime number";
            }else{
                cout<<"Not a Prime number";
            }
        
}

void prime_optimal(int n){
        int c=0;

        for(int i=1;i*i<=n;i++){
            
            if(n%i == 0){
                c++;

                if(n/i != i ) c++;
            }
        }
        if(c==2){
                cout<<"Prime number";
            }else{
                cout<<"Not a Prime number";
            }
}

int main(){

    int n=12;
    // prime(n);
    prime_optimal(n);
    return 0;
}