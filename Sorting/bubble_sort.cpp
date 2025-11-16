#include<iostream>

using namespace std;


void bubbleSort(int arr[],int n){     //O(n^2)

    
    for(int i=0;i<=n;i++){

        bool isSwapped=false;
        
        for(int j=i+1;j<n-1;j++){

            if (arr[i] > arr[j]){
                
                int temp=arr[j];
                arr[j] = arr[i];
                arr[i] = temp;

                isSwapped=true;
            }
        }

        if(!isSwapped){
            break;                  //O(n)
        }
    }
    
    for(int i=0;i<n;i++) cout<<arr[i] << endl;
}





int main(){

    int arr[10] = {6,3,4,2,1,9,8,7,11,5};
    // int arr[10] = {1,2,3,4,5,6,7,8,9,0};

    int n=sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr,n);
    return 0;
}