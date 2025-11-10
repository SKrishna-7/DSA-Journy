#include<iostream>
using namespace std;

//method 1
void print_name(string name,int n){

    if (n < 1) return;
    
    cout << name << endl;
    print_name(name,n-1);
}

//method 2
void print_name_2(string name,int n,int count){

    if (count == n) return;
    
    cout << name << endl;
    print_name_2(name,n, count+1);
}

//method 2 - updated
void print_name_3(string name,int n){

    int count=0;
    if (count == n) return;
    
    cout << name << endl;
    print_name_2(name,n, count+1);
}


int main(){

    string name="Suresh";
    int n=5;

    // print_name(name,n);
    // print_name_2(name,n,0);
    print_name_3(name,n);

    return 0;
}