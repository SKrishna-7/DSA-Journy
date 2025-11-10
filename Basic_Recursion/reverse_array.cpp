#include<iostream>

using namespace std;

void reverse_array(int l,int r,int arr[]){

    
    if (l>=r) {
        return ;
    }
    
    int temp=arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    reverse_array(l+1,r-1,arr);
}


void reverse_array_1(int i,int n,int arr[]){

    
    if (i == n/2) {
        return ;
    }
    
    int temp=arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;

    reverse_array_1(i+1,n,arr);
}

void reverse_array_2(int i,int arr[]){

    
    if (i>=0) {
        return ;
    }
    
    int temp=arr[i];
    arr[i] = arr[i+1];
    arr[i] = temp;

    reverse_array_2(i+1,arr);
}


int main(){

    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);

    // reverse_array(0,size-1,arr);
    // reverse_array_1(0,size,arr);
    reverse_array_2(0,arr);

    for(auto a:arr){
        cout << a << endl;
    }
    return 0;
}