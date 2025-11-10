#include<iostream>
using namespace std;

void print_1toN(int n,int count=1){

    if (count>n) return;

    
    cout<< count << endl;;

    print_1toN(n,count+1);
    

    
}


int main(){

    int n=5;

  
    print_1toN(n);

    return 0;
}