#include<iostream>
#include<vector>

using namespace std;


void moveZerosToEnd_Brute(vector<int> &arr,int n){

    vector<int> temp;

    for(int i=0;i<n;i++){
        if(arr[i]!=0){                                  //O(n)
            temp.push_back(arr[i]);
        }
    }

    for(int i=0;i<temp.size();i++){              //O(x) 
        arr[i] = temp[i];
    }

    for(int i=temp.size();i<n;i++){
        arr[i] = 0;                          //O(n-x)  
    }


   
    //O(n) + O(x) + O(n-x) == > O(2n)

}




void moveZerosToEnd_Optimal(vector<int> &arr,int n){

    int p1=-1;
 
    for(int i=0;i<n;i++){
        if(arr[i]==0){                 //O(x)
            p1=i;
            break;
        }
    }

    for(int j=p1+1;j<n;j++){                     //O(n-x)

        if(arr[j] != arr[p1]){
            
            int temp=arr[j];
            arr[j] = arr[p1];
            arr[p1] = temp;

            p1++;
        }

    }
  

    //O(x) + O(n-x) = O(n)
}


int main(){

    vector<int> arr={1,0,0,2,0,3,4,0,5,0,6};
    int n=arr.size();

    // moveZerosToEnd_Brute(arr,n);
    moveZerosToEnd_Optimal(arr,n);

    cout<<"Moved Zeros to End : ";
     for(auto i:arr){
        cout<<i<<" ";
    }


    return 0;
}