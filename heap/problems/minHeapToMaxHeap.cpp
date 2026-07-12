#include<iostream>
#include<vector>

using namespace std;


void minToMaxHeap(vector<int> &arr,int current,int n){



    while(true){

        int largest = current;

        int left = 2*current+1;
        int right = 2*current+2;

        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;

        if(largest == current) break;

        swap(arr[current],arr[largest]);

        current = largest;

    }
}
   
int main(){

    vector<int> arr={10,20,30,21,23};
    int n=arr.size();

   for(int i = n/2 -1; i>=0; i--)
        minToMaxHeap(arr,i,n);

    for(int &i : arr){
        cout<<i<<" ";
    }
    
    
    return 0;
}