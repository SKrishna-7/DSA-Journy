#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>


using namespace std;

int subarrayWithK(vector<int> &nums, int k){

    int n=nums.size();
    int count=0;

    for(int i=0;i<n;i++){

        unordered_set<int> st;

        for(int j=i;j<n;j++){
            
            st.insert(nums[j]);

            if(st.size() == k){
                count++;
            }
            else if(st.size() > k) break;
        }
    }

    return count;
}

int atMost(vector<int> &nums,int k){
    
    int r=0 , l=0;
    int n=nums.size();

    int result=0;
    int distCount=0;

    unordered_map<int, int> freq;
    
    while(r < n){

        freq[nums[r]]++;

        if(freq[nums[r]] == 1){
            distCount++;
        }

        while(distCount > k){
            
            freq[nums[l]]--;
            if(freq[nums[l]] == 0) distCount--;

            l++;
        }

        result += r -l +1;
        r++;
    }

    return result;
}
int subarrayWithK_optimal(vector<int> &nums, int k){

    return atMost(nums,k) - atMost(nums,k-1);
}
int main(){

    vector<int> nums={1,2,1,2,3};
    int k=2;

    cout<<subarrayWithK_optimal(nums,k);

    return 0;
}