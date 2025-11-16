#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;



int LargestElement(vector<int> &arr,int n){

  int largest=arr[0];

  for(int i=1;i<n;i++){

    if (arr[i]>largest) largest = arr[i];    
  }

  return largest;

}


// BruteForce

int SecondLargest_Bruteforce(vector<int> &arr,int n){

    // int largest=LargestElement(arr,n);
    
    int second_largest=0;

    sort(arr.begin(),arr.end());   // O(n log n)
    int largest=arr[n-1];

   for(int i=n-1;i > 0;i--){                            // ~~ O (n)

        if(arr[i] != largest) {
          second_largest=arr[i];
          break;
        }
   }

   return second_largest;
}


//Better

int SecondLargest_Better(vector<int> &arr,int n){

    int largest=LargestElement(arr,n);   // O(n)
    
    int second_largest=INT_MIN;

    
    for(int i=0;i<n;i++){               // O(n)

        if(arr[i] > second_largest && arr[i] != largest){
            second_largest=arr[i];
        }
    }

   return second_largest;
}


//Optimal

int SecondLargest_Optimal(vector<int> &arr,int n){

    int largest=arr[0];
    
    int second_largest=INT_MIN;

    
    for(int i=1;i<n;i++){               // O(n)

        if(arr[i] > largest){
            second_largest=largest;
            largest=arr[i];
        }

        else if(arr[i] > second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }

   return second_largest;
}



int main(){

    vector<int> arr={2,3,5,1,6,2,6,7,7,0};  
    int n=arr.size();

    cout<<SecondLargest_Bruteforce(arr,n);  // O(n log n)/

    cout<<SecondLargest_Better(arr,n);  // O(n) + O(n) = O(2n)

    cout<<SecondLargest_Optimal(arr,n);  // O(n) + O(n) = O(2n)


    return 0;
}
