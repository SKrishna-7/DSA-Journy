#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum_brute(vector<int> &nums,int n,int target){

    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                for(int l=k+1;l<n;l++){

                    long long sum=nums[i] + nums[j] ;
                    sum+= nums[k] + nums[l];
                    
                    if(sum == target){
                        vector<int> temp={nums[i] , nums[j] , nums[k],nums[l]};
                        
                        sort(temp.begin(),temp.end());
                        
                        st.insert(temp);
                        
                    }
                }
            }
        }
    }

    vector<vector<int>> res(st.begin(),st.end());

    return res;
}



vector<vector<int>> fourSum_better(vector<int> &nums,int n,int target){

    // nums[i] + nums[j] + nums[k] + nums[l] = target
    // nums[l] =target - (nums[i] + nums[j] + nums[k])

    set<vector<int>> triplets;
    
    for(int i=0;i<n;i++){
        
        for(int j =i+1; j<n;j++){
            set<int> hmap;
            for(int k=j+1;k<n;k++){

                long long l = -(nums[i] + nums[j] + nums[k]);

                long long need=target + l;
                
                if(hmap.find(need) != hmap.end()){
                    
                    vector<int> temp = {nums[i] , nums[j],nums[k],(int)need};
                    
                    sort(temp.begin(),temp.end());
                    
                    triplets.insert(temp);
                }
                hmap.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> res(triplets.begin(),triplets.end());

    return res;


}


vector<vector<int>> fourSum_optimal(vector<int> &nums,int n,int target){

  
    
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());


    for(int i=0;i<n;i++){
        
        if(i>0 && nums[i] == nums[i-1]) continue;
        
        for(int j=i+1;j<n;j++){
            
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            
            int k=j+1;
            int l=n-1;
        
            while(k<l){
                long long sum=nums[i] + nums[j] + nums[k] + nums[l];
                
                if(sum == target){
                    vector<int> temp = {nums[i] , nums[j] , nums[k],nums[l]};
                    res.push_back(temp);
                    k++;
                    l--;

                    while(k<l && nums[k] == nums[k-1]) k++; 
                    while(k<l && nums[l] == nums[l-1]) l--; 
                }
                else if  (sum > target){
                    l--;
                }
                else if(sum < target){
                    k++;
                }
            }
        }
    }
    return res;


}

int main(){

    vector<int> nums = {4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    int n=nums.size();

    // vector<vector<int>> ans=fourSum_brute(nums,n,target);
    // vector<vector<int>> ans=fourSum_better(nums,n,target);
    
    vector<vector<int>> ans=fourSum_optimal(nums,n,target);
    for(auto &i:ans){
        for(auto &val:i){

            cout << val << " ";
        }
        cout<<endl;
    }

    return 0;
}