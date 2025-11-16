#include<iostream>

using namespace std;


void selectionSort(int arr[],int n){

    
    for(int i=0;i<n;i++){
        
        int min_index=i;

        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index=j;
            }
        }
        
        int temp=arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    
    for(int i=0;i<n;i++) cout<<arr[i] << endl;
}



int main(){

    int arr[10] = {6,3,4,2,1,9,8,7,11,5};
    int n=sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr,n);
    return 0;
}