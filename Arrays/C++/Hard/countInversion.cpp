#include <iostream>
#include <vector>
using namespace std;

int countInversion_brute(vector<int> nums,int n){
    
    int count=0;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] > nums[j]) count++;
        }
    }

    return count;
    
}
// Optimal using mergeSort

int merge(vector<int> &nums , int low,int mid,int high){
    int cnt=0;
    vector<int> temp;
    
    int left=low;
    int right=mid+1;
    
    while(left<=mid && right<=high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            cnt+=mid-left+1;
            temp.push_back(nums[right]);
            right++;
        }
    }
    
    while(left<=mid){
         temp.push_back(nums[left]);
        left++;
    }
    
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    
    for(int i=0;i<temp.size();i++){
        nums[low+i] = temp[i];
    }
    
    return cnt;
}

int divide(vector<int> &nums,int low,int high){
    
    int cnt=0;
    if(low>=high) return cnt ;
    
    int mid = (low + high) / 2;
    
    // split left
    cnt+=divide(nums,low,mid);
    // split right
    cnt+=divide(nums,mid + 1,high);
    
    cnt+=merge(nums,low,mid,high);
    
    return cnt;
}

int countInversion_Optimal(vector<int> &nums,int n){
    
   return divide(nums,0,n-1);

}


int main() {
    
    // vector<int> nums={5,4,3,2,1};
    vector<int> nums={4,7,8,6,3,2,1};
    int n=nums.size();
    
    // cout << countInversion_brute(nums,n); 
    cout << countInversion_Optimal(nums,n);
    
    
    return 0;
}