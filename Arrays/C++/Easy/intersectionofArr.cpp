#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> intersectionofArr_Brute(vector<int> &arr1,vector<int> &arr2){

    int n1=arr1.size();
    int n2=arr2.size();

    vector<int> visited(n2,0);
    vector<int> intersection;

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){

            if(arr1[i] == arr2[j] && visited[j] != 1){
                intersection.push_back(arr1[i]);
                visited[j]=1;
                break;
            }

            if(arr2[j] > arr1[i]) break;
        }
    }

    
   return intersection;
}



vector<int> intersectionofArr_Optimal(vector<int> &arr1,vector<int> &arr2){

        int n1=arr1.size();
        int n2=arr2.size();

        int p1=0;
        int p2=0;

        vector<int> intersection;

        while(p1<n1 && p2<n2){

            if(arr1[p1] < arr2[p2]) p1++;
            
            else if(arr2[p2] < arr1[p1]) p2++;

            else{
                   intersection.push_back(arr1[p1]);
                    p1++;
                    p2++;
            }

}
    return intersection;
}

int main(){

    
    vector<int> arr1={1,2,3,4,3,5,6};
    vector<int> arr2={2,3,3,4,7,8,9};

//    vector <int> intersectionofarr= intersectionofArr_Brute(arr1,arr2);
   vector <int> intersectionofarr= intersectionofArr_Optimal(arr1,arr2);

    cout<<"Intersection of arr1 and arr2 : ";
   for(auto &i:intersectionofarr){
    cout<<i<<" ";
   }
    
    

    return 0;
}
