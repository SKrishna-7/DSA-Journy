#include<iostream>
#include<vector>

using namespace std;

bool isMinHeap(vector<int>& arr) {

    int n = arr.size();

    for(int i=(n/2)-1;i>=0;i--){


        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] < arr[i]) return false;
        if(right < n && arr[right] < arr[i]) return false;
         

    }

    return true;
}
   
int main(){

    vector<int> arr={10,20,30,21,23};
    
    cout << boolalpha << isMinHeap(arr);
    
    return 0;
}