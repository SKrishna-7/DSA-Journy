#include<iostream>
#include<vector>
#include<set>

using namespace std;


void removeDup_brute(vector <int>&arr,int n){

    set<int> map;

    for(int i=0;i<n;i++){

        map.insert(arr[i]);   //O(n log n)  
    }

    int index=0;

    for(auto &i:map){
        arr[index]=i;           //O(n)
        index++;
    }

    
    for(int i=0;i<index;i++) cout<<arr[i] << " ";
    
    for(int i=index;i<n;i++) arr[i] =-1;
    
    cout<<endl;
    for(int i=0;i<n;i++) cout<<arr[i] << " ";
}


void removeDup_optimize(vector<int> &arr,int n){

    int pointer=0;
    

    for(int i=1;i<n;i++){

        if(arr[i]!=arr[pointer]){

            arr[pointer+1] = arr[i];
            pointer++;

        }
    }

   
    for(int i=0;i<=pointer;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    vector<int> arr={1,1,2,2,3,4,5,6,7,7};
    int n=arr.size();

    // removeDup_brute(arr,n);
    removeDup_optimize(arr,n);
    return 0;
}