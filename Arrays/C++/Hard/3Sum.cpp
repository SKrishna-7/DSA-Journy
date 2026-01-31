#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum_brute(vector<int> &nums,int n){

    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                int sum=nums[i] + nums[j] + nums[k];
                
                if(sum == 0){
                    vector<int> temp={nums[i] , nums[j] , nums[k]};
                    
                    sort(temp.begin(),temp.end());

                    st.insert(temp);
                    
                }
            }
        }
    }

    vector<vector<int>> res(st.begin(),st.end());

    return res;
}



vector<vector<int>> threeSum_better(vector<int> &nums,int n){

    // nums[i] + nums[j] + nums[k] = 0
    // nums[k] = - (nums[i] + nums[j])

    set<vector<int>> triplets;
    
    for(int i=0;i<n;i++){
        
        set<int> hmap;
        for(int j =i+1; j<n;j++){

            int k = -(nums[i] + nums[j]);

            if(hmap.find(k) != hmap.end()){

                vector<int> temp = {nums[i] , nums[j],k};

                sort(temp.begin(),temp.end());

                triplets.insert(temp);
            }
            hmap.insert(nums[j]);
        }
    }

    vector<vector<int>> res(triplets.begin(),triplets.end());

    return res;


}


vector<vector<int>> threeSum_optimal(vector<int> &nums,int n){

  
    
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());


    for(int i=0;i<n;i++){
        
        if(i>0 && nums[i] == nums[i-1]) continue;

        int j=i+1;
        int k=n-1;

        while(j<k){
            int sum=nums[i] + nums[j] + nums[k];

            if(sum == 0){
                vector<int> temp = {nums[i] , nums[j] , nums[k]};
                res.push_back(temp);
                k--;
                j--;
            }
            if  (sum > 0){
                    k--;
            }
            if(sum < 0){
                j++;
            }
        }
    }
    return res;


}

int main(){

    vector<int> nums = {-1,0,1,2,-1,-4};
    int n=nums.size();

    // vector<vector<int>> ans=threeSum_brute(nums,n);
    // vector<vector<int>> ans=threeSum_better(nums,n);
    vector<vector<int>> ans=threeSum_optimal(nums,n);

    for(auto &i:ans){
        for(auto &val:i){

            cout << val << " ";
        }
        cout<<endl;
    }

    return 0;
}