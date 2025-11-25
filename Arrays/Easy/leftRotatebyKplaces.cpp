#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void leftRotateKplace_Brute(vector<int> &arr,int n,int k){

    vector<int> temp;

    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }

    for(int i=0;i<n-k;i++){
        arr[i] = arr[i+k];
    }

    // for(int i=0;i<k;i++){
    //     arr[(i+k)+1] = temp[i];  // method-1
    // }

    for(int i=n-k;i<n;i++){
        arr[i] = temp[i-(n-k)];  // method-1
    }

    // int index=0;
    // for(int i=k;i<n;i++){
    //     arr[i] = temp[index];     // method-2
    //     index++;
    // }

}


void rotate(vector<int> &arr,int l,int r){

    while(l<=r){
        
        int temp=arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        l++;
        r--;
    }

}
void leftRotateKplace_Optimal(vector<int> &arr,int n,int k){

    rotate(arr,0,k-1);
    rotate(arr,k,n-1);
    rotate(arr,0,n-1);


}


int main(){
    
    vector<int> arr={1,2,3,4,5,6,7};
    int k=8;
    int n=arr.size();
    k=k%n;
    
    // leftRotateKplace_Brute(arr,n,k);
    leftRotateKplace_Optimal(arr,n,k);

    cout<<"Rotated Array for K places : ";
    for(auto i:arr){
        cout<<i<<" ";
    }


 
    return 0;
}