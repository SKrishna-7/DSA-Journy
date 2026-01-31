#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sort_012_brute(vector<int> &arr,int n){

    vector<int> temp_0;
    vector<int> temp_1;
    vector<int> temp_2;

    for(int i=0;i<n;i++){
        if(arr[i] == 0) temp_0.push_back(arr[i]);
        else if(arr[i] == 1) temp_1.push_back(arr[i]);
        else temp_2.push_back(arr[i]);
    }

    int index=0;
    for(int i=0;i<temp_0.size();i++){
        arr[index] = temp_0[i];
        index++;
    }
    for(int i=0;i<temp_1.size();i++){
        arr[index] = temp_1[i];
        index++;
    }
    for(int i=0;i<temp_2.size();i++){
        arr[index] = temp_2[i];
        index++;
    }

// TC - O(2N) SC- O(N)
}



void sort_012_better(vector<int> &arr,int n){

   int count_0=0;
   int count_1=0;
   int count_2=0;

    for(int i=0;i<n;i++){
        if(arr[i] == 0) count_0++;
        else if(arr[i] == 1) count_1++;
        else count_2++;
    }

    int index=0;
    for(int i=0;i<count_0;i++){
        arr[index] = 0;
        index++;
    }
    for(int i=0;i<count_1;i++){
        arr[index] = 1;
        index++;
    }
    for(int i=0;i<count_2;i++){
        arr[index] = 2;
        index++;
    }
   


}


void sort_012_optimal(vector<int> &arr,int n){
    int low=0;
    int mid=0;
    int high=n-1;


    while(mid<high){
        if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }

        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

}
int main(){

    vector<int> arr={2,0,0,1,2,1,1,2,0};  
    int n=arr.size();
    
    // sort_012_brute(arr,n);
    // sort_012_better(arr,n);

    sort_012_optimal(arr,n);
    for(auto &i:arr){
        cout<< i <<" ";
    }

    return 0;
}
