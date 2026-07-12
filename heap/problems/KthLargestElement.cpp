#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int KthLargest_brute(vector<int> &arr,int k){

    sort(arr.begin(),arr.end());
    return arr[arr.size() - k];
}

int KthLargest_better(vector<int> &arr,int k){

    priority_queue<int> pq;

    for(int num:arr){
        pq.push(num);           // O(n)
    }

    for(int i=1;i<k;i++) pq.pop();     // O(k-1) x O(log N)

    return pq.top();

}


int KthLargest_optimal(vector<int> &arr,int k){

    priority_queue<int,vector<int>,greater<int>> pq;  // Min Heap

    for(int num:arr){
    
        pq.push(num);           

        if(pq.size() > k) pq.pop();
    }

    
    return pq.top();

} // O(N log K)


int main(){

    vector<int> arr={10,20,30,25,15};
    int k = 2;

    cout<<endl;
    cout<<KthLargest_optimal(arr,k);
    cout<<endl;
    return 0;
}