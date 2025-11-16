#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int frequency(int arr[],int n,int size){

    int count=0;
    for(int i=0; i<size;i++){

        if(arr[i] == n) {
            count++;
        }

    }
        return count;

}                                   

//Time complicity  O(n) 

void frequency_arr_hashing(int arr[],int size){

    int empty_arr[11] ={0};   // space com => O(n)

    for(int i=0;i<size;i++){
        
        empty_arr[arr[i]]++;
    }

    
    for(int j=0;j<size;j++){
        
        if(empty_arr[j] > 0)
        cout <<"\nfrequency of " <<j << " ->" << empty_arr[j];
    }
}

void frequrncy_map(int arr[],int size){

    // map<int,int> hash; // O(log n)  
    unordered_map<int,int> hash; // O(1)

    for(int i=0;i<size;i++){
        hash[arr[i]]++;
    }

    for(auto i:hash){
        cout << i.first << "=>" << i.second <<endl;
    }   
}       //O(log n)



int main(){

    int arr [10] ={1,2,2,2,4,5,6,6,7,4};

    for(auto i : arr){
        cout<<i<<endl;   
    }

    int size=sizeof(arr) / sizeof(arr[0]);

    // cout <<"Count : "<< frequency(arr,2,size);
    
    // frequency_arr_hashing(arr,size);


    frequrncy_map(arr,size);
    

    return 0;
}