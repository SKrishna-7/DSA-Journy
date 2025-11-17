#include<iostream>
#include<vector>
#include<set>

using namespace std;

void leftRotateByOnePlace_brute(vector<int>&arr,int n){

    vector<int> temp(n);       // O(n) space complexity

    
    for(int i=1;i<n;i++){
        temp[i-1] = arr[i];
    }

    temp[n-1]=arr[0];

    for(auto i:temp){
        cout<<i<<" ";
    }

}


void leftRotateByOnePlace_optimal(vector<int>&arr,int n){

    int temp=arr[0];

    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;
    for(auto i:arr){
        cout<<i<<" ";
    }

} 



int main(){

    vector<int> arr={1,2,3,4,5,6,7};
    int n=arr.size();

   leftRotateByOnePlace_brute(arr,n);
   cout<<endl;
   leftRotateByOnePlace_optimal(arr,n);

    return 0;
}