#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int fruitsInBasket_brute(vector<int> &nums,int n){

    int maxLen=0;

    for(int i=0;i<n;i++){

        unordered_set<int> st;
        
        for(int j=i;j<n;j++){

            st.insert(nums[j]);

            if(st.size() <= 2){
                maxLen = max(maxLen,j-i+1);
            }else break;

        }
    }

    return maxLen;
}



int fruitsInBasket_better(vector<int> &nums,int n){

    int maxLen=0;

    int r=0,l=0;
    unordered_map<int,int> m;

    while(r<n){

        m[nums[r]]++;

        while(m.size() > 2){

            m[nums[l]]--;
            if(m[nums[l]] == 0 ) m.erase(nums[l]);
            l++;
        }
        if(m.size() <= 2){
            maxLen = max(maxLen,r-l+1);
        }
        r++;
    }
  
    return maxLen;
}



int fruitsInBasket_optimal(vector<int> &nums,int n){

    int maxLen=0;

    int r=0,l=0;
    unordered_map<int,int> m;

    while(r<n){

        m[nums[r]]++;

        if(m.size() > 2){

            m[nums[l]]--;
            if(m[nums[l]] == 0 ) m.erase(nums[l]);
            l++;
        }
        if(m.size() <= 2){
            maxLen = max(maxLen,r-l+1);
        }
        r++;
    }
  
    return maxLen;
}


int main(){

    cout<<endl;

    vector<int> nums={1, 2, 3, 2, 2};
    int n=nums.size();
    
    cout<<fruitsInBasket_optimal(nums,n);

    cout<<endl;

    return 0;
}