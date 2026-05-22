#include<iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool linear_search(vector<int>& a, int num){

     int n = a.size(); 
        // Traverse through the array 
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
}
int longest_conseq_brute(vector<int> nums,int n) {

    int longest=1;
    bool istrue=false;
    
    for(int i=0;i<n;i++){
        
        int x=nums[i];
        int c=1;
    
    while(linear_search(nums,x+1)==true){
        x=x+1;
        c++;
    }

    longest=max(longest,c);
}
    return longest;
}

int longest_conseq_better(vector<int> nums,int n) {

    int longest=INT_MIN;
    int lastSmaller=INT_MIN;

    sort(nums.begin(),nums.end());

    int c=0;
    for(int i=0;i<n;i++){

        if(nums[i]-1 == lastSmaller) {
            c++;
            lastSmaller=nums[i];
            }

        else if(nums[i] != lastSmaller){
            c=1;
            lastSmaller=nums[i];
        }
        longest=max(longest,c);
    }
    return longest;
}


int longest_conseq_optimal(vector<int> nums,int n) {

    unordered_set<int> h_map(nums.begin(),nums.end());
    int longest=1;


    for(int num:h_map){

        if(h_map.find(num-1) == h_map.end()){
            int crt_num=num;
            int streaks=1;
            
            while(h_map.find(crt_num+1) != h_map.end()){
                streaks++;
                crt_num++;
            }

            longest=max(longest,streaks);
        }
    }

    return longest;

}

int main(){

    vector<int> nums={0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
    int n=nums.size();

    // cout<<longest_conseq_brute(nums,n);
    // cout<<longest_conseq_better(nums,n);
    cout<<longest_conseq_optimal(nums,n);

    return 0;
}