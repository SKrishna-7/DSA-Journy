#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> next_permutation_optimal(vector<int> &arr){

    int size=arr.size();

    int index=-1;
    for(int i=size-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            index=i;
            break;
        }
    }
    
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }

    for(int i=size-1;i>index;i++){
        if(arr[i] > arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

    reverse(arr.begin()+index+1,arr.end());
    return arr;
}

int main(){

    vector<int> arr={1,2,3};

   
    for(auto &i: next_permutation_optimal(arr)){
        cout<< i<<" ";
    }

    return 0;
}