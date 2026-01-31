#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void mergeSortedArr_brute(vector<long long> &arr1,vector<long long>&arr2,int n,int m){

    vector<long long> temp(n+m); 

    for(int i=0;i<n;i++){
        // temp.push_back(arr1[i]);
        temp[i]=arr1[i];
    }

    for(int i=0;i<m;i++){
        // temp.push_back(arr1[i]);
      temp[i+n] = arr2[i];                         // O(n + m)
    }

    sort(temp.begin(),temp.end());            // O(N log N) , N=n+m


    for(int i=0;i<n;i++){               // 
        arr1[i] = temp[i];
    }
    
    for(int i=0;i<m;i++){                
        arr2[i] = temp[i+n];
    }                                       //              O(n+m)

//total TC => O(n+m) + O(n+m) + O(N log N)
//SC =>O(n+m)


    return ;
}


void mergeSortedArr_better(vector<long long> &arr1,vector<long long>&arr2,int n,int m){

    vector<long long> temp(n+m); 

    int p1=0;
    int p2=0;
    int index=0;

    while(p1<n && p2<m){

        if(arr1[p1] <= arr2[p2]){
            temp[index] = arr1[p1];
            index++;
            p1++;
        }
        else if(arr1[p1] >= arr2[p2]){
            temp[index] = arr2[p2];
            index++;
            p2++;
        }
    }

    while(p1<n){
        temp[index] = arr1[p1];
        index++;
        p1++;
    }
    while(p2<m){
        temp[index] = arr2[p2];
        index++;
        p2++;
    }

    
    // for(auto &i:temp){
    //     cout<<i<<" ";
    // }

    for(int i=0;i<n;i++){
        arr1[i] = temp[i];
    }
    for(int i=0;i<m;i++){
        arr2[i] = temp[i+n];
    }

//total TC => O(n+m) + O(n+m) 
// SC => O(n+m)


    return ;
}

//Optimal


void mergeSortedArr_optimal(vector<long long> &arr1,vector<long long>&arr2,int n,int m){

    int low=n-1;
    int high =0;
    
    while(low>=0 && high < m){
        
        if(arr1[low] > arr2[high]){
            swap(arr1[low],arr2[high]);
            low--;
            high++;
       }else{
        break;
       }
    }
    


//total TC => O(n+m) + O(n+m) + O(N log N)
//SC =>O(n+m)
    return ;
}


// Gap method


void mergeSorted_optimal_gapmethod(vector<long long>&arr1,vector<long long>&arr2){

    int n=arr1.size();
    int m=arr2.size();
    int N=n+m;

    int gap=(N/2) +(N%2);

    
    
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        
        while(right<N){

            // pointers are crossover
            if(left < n && right >=n){

                if(arr1[left] > arr2[right - n]){
                    swap(arr1[left],arr2[right - n]);
                }
            }

            // 2 pointers are in first array
            else if(left<n && right <n){
                 if(arr1[left] > arr1[right]){
                    swap(arr1[left],arr1[right]);
                }
            }

            // 2 pointers are in second array
            else{   
                 if(arr2[left - n] > arr2[right - n]){
                    swap(arr2[left - n],arr2[right - n]);
                }
            }


        left++;
        right++;
    }
    if (gap==1) break;
    gap=(gap/2) + (gap%2);
}

}



int main(){

    vector<long long> arr1={0,1,2,3,6};
    vector<long long> arr2={5,7,8,9};    // arr1={0,2,3,4,5} arr2= {6,7,8,9}

    int n=arr1.size();
    int m=arr2.size();

    // Merge 2 Sorted Arr , Inplace

    // mergeSortedArr_brute(arr1,arr2,n,m);
    // mergeSortedArr_better(arr1,arr2,n,m);
    mergeSortedArr_optimal(arr1,arr2,n,m);

    // mergeSorted_optimal_gapmethod(arr1,arr2);
    
    cout << "Arr1: ";
    for (auto val : arr1) cout << val << " ";
    cout << "\nArr2: ";
    for (auto val : arr2) cout << val << " ";
    
    
    return 0;
}

