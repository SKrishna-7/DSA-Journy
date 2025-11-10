#include<iostream>

using namespace std;


int fibanacii(int n){

    if (n<=1) return n;

    int last=fibanacii(n-1);
    int first=fibanacii(n-2);

    return first + last;

}
int main(){

    int n=8;
   
   cout<< fibanacii(n);

    return 0;
}