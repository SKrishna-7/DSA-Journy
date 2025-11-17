#include<iostream>
#include<vector>
#include<map>

using namespace std;

int noThatAppearsOnce_Brute(vector<int> arr,int n){

        for(int i=0;i<n;i++){

            int counter=0;
            for(int j=0;j<n;j++){

                if(arr[i] == arr[j]){
                    counter++;
                }
            }
            if(counter==1){
                return arr[i];
            }
        }

        return -1;

}

int noThatAppearsOnce_Better(vector<int> arr,int n){

    int max=arr[0];

    for(auto &i:arr){                    // O(n)
        if(i > max) max=i;
    }

    vector<int> map(max+1);

    for(auto &i:arr){              // O(n)
        map[i]++;
    }

    // int index=0;
    // for(auto &i:map){           // method - 1
    //     if(i==1) cout<<index;
    //     index++;  
    // }

    for(int i=1;i<map.size();i++){
        if(map[i] == 1) return i;           // method-2            // O(n)
    }

    return -1;


    //.Now, using array hashing it is difficult to hash the elements of the array if it contains negative numbers or a very large number.
    //  So to avoid these problems, we will be using the map data structure to hash the array elements.
}


int noThatAppearsOnce_Better_1(vector<int> arr,int n){

        map <int,int> map;

        for(auto &i:arr){
            map[i]++;              //O(N log M)
        }

         for(auto &i:map){                // O(n/2) + 1
            if(i.second == 1){
                return i.first;
            }

        }

        return -1;
}       // O(N log M) + O(n/2 + 1)   | m -size of map ,which is n/2 + 1



int noThatAppearsOnce_Optimal(vector<int> &arr){

    int xr = 0;

    for(auto &i:arr){
        xr=xr ^ i;
    }

    return xr;

    //O(n)
}

int main(){

    vector<int> arr={1,2,2,3,3,1,4,5,4,-2,-2};
    int n=arr.size();

    // cout<<noThatAppearsOnce_Brute(arr,n);

//    cout<<noThatAppearsOnce_Better(arr,n);

//    cout << noThatAppearsOnce_Better_1(arr,n);

   cout << noThatAppearsOnce_Optimal(arr); 

    return 0;
}