#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> KSortedArray_brute(vector<int> &arr,int k){

    sort(arr.begin(),arr.end());
    
    return arr;
}


vector<int> KSortedArray_optimal(vector<int> &arr,int k){

    priority_queue<int,vector<int>,greater<int>> pq;  // Min Heap

    vector<int> ans;

    for(int i=0;i<=k && i < arr.size();i++){
        pq.push(arr[i]);
    }

    for(int i=k+1;i<arr.size();i++){

        ans.push_back(pq.top());
        
        pq.pop();

        pq.push(arr[i]);
    }

    while(!pq.empty()){
        
        ans.push_back(pq.top());
        pq.pop();
    }

    
    return ans; 

} // O(N log K)


int main(){

    vector<int> arr={6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    cout<<endl;

    for(int i:KSortedArray_optimal(arr,k)){
        cout<<i << " ";

    }
    cout<<endl;
    return 0;
}