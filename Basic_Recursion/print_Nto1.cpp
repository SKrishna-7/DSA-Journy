#include<iostream>
using namespace std;

void print_Nto1(int n,int count=1){

    if (count>n) return;

    
    
    print_Nto1(n,count+1);
    cout<< count << endl;;
    

    
}

int main(){

    int n=5;

    print_Nto1(n);

    return 0;
}