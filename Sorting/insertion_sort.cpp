#include<iostream>

using namespace std;

void insertion_sort(int arr[],int n){

     for(int i=0;i<=n-1;i++){

       int j=i;

       while(j>0){
            if(arr[j-1] > arr[j]){

                int temp=arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            j--;
        }
        
        
    }
    
    for(int i=0;i<n;i++) cout<<arr[i] << endl;
}


int main(){

    int arr[10]={7,4,2,1,3,3,8,9,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr,n);

    return 0;
}