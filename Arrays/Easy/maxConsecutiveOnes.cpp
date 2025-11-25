#include<iostream>
#include<vector>

using namespace std;

int mostConsecutiveOnce(vector<int> &arr,int n){

    int maxi=0;
    int counter=0;


    for(auto &i:arr){

        if(i == 1){
            counter++;
            maxi=max(maxi,counter);
        }else counter=0;

    }

    return maxi;
}

int main(){

    vector<int> arr={1,2,1,1,3,4,1,1,1,5};
    int n=arr.size();

    cout<<mostConsecutiveOnce(arr,n);

    return 0;
}