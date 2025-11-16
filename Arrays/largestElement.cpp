#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// BruteForce

int LargestElement_BruteForce(vector<int> arr,int n){

    // Sort the arr and return the last element
    sort(arr.begin(),arr.end());            // O(n log n)

    return arr[n-1];

}


//Optimized

int LargestElement_Optimized(vector<int> arr,int n){

  int largest=arr[0];

  for(int i=1;i<n;i++){

    if (arr[i]>largest) largest = arr[i];      // O(n)
  }

  return largest;


}


int main(){

    vector<int> arr={2,3,5,1,2,7,0};  
    int n=arr.size();

    cout<<LargestElement_BruteForce(arr,n);  // O(n log n) 
    cout<<LargestElement_Optimized(arr,n);   // O(n)

    return 0;
}

/**
 

Optimal Approach: 

.Create a max variable and initialize it with arr[0].
.Use a for loop and compare it with other elements of the array
.If any element is greater than the max value, update max value with the element’s value
.Print the max variable.

**/