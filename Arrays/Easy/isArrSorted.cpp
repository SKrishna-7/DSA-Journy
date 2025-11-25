#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool isArraySorted(vector<int> &arr,int n){

    bool isSorted=false;

    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1])  isSorted=false;

        else isSorted=true;
    }

  
   return isSorted;
}



int main(){

    vector<int> arr={2,3,5,1,6,2,6,7,7,0};  
    // vector<int> arr={1,2,3,4,5};  
    int n=arr.size();

    if(isArraySorted(arr,n)){
        cout<<"Arr is Sorted..!";
        
    }else{
        cout<<"Arr is not sorted..!";
    } 

    return 0;
}
