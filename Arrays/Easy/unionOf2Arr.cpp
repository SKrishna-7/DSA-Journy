#include<iostream>
#include<vector>
#include<set>

using namespace std;


vector<int> unionOfArr_Brute(vector<int> &arr1,vector<int> &arr2){

    vector<int> union_arr;

    int n1=arr1.size();
    int n2=arr2.size();

    set<int> union_set;

    for(int i=0;i<n1;i++){
        union_set.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        union_set.insert(arr2[i]);
    }

   

    for(auto &i:union_set){
        union_arr.push_back(i);
    }

    // for(auto &i:union_arr){
    //     cout<<i<<" ";
    // }

    return union_arr;
}


vector<int> unionOfArr_Optimal(vector<int> arr1,vector<int>arr2){

        int n1=arr1.size();
        int n2=arr2.size();

        int p1=0;
        int p2=0;

        vector<int> union_arr;

        while(p1<n1 && p2<n2){

            if(arr1[p1] <= arr2[p2] ){

                if(union_arr.size() == 0 || union_arr.back() != arr1[p1])
                {
                    union_arr.push_back(arr1[p1]);
                }
                p1++;
            }

            else{

                if(union_arr.size() == 0 || union_arr.back() != arr2[p2] ){

                    union_arr.push_back(arr2[p2]);
                }
                p2++;
            }
        }

        while(p1<n1){
            union_arr.push_back(arr1[p1]);
            p1++;
        }

        while(p2<n2){
            union_arr.push_back(arr2[p2]);
            p2++;
        }

        return union_arr;

}


int main(){

    vector<int> arr1={1,2,3,4,5,6};
    vector<int> arr2={2,3,3,4,7,8,9};

//    vector <int> unionofarr= unionOfArr_Brute(arr1,arr2);
   vector <int> unionofarr= unionOfArr_Optimal(arr1,arr2);

   for(auto &i:unionofarr){

    cout<<i<<" ";
   }
    



    return 0;
}