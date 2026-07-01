#include <iostream>
#include<vector>
using namespace std;

int trapRainWater_brute(vector<int> &height,int n){
   
    int total=0;
    
    for(int i=0;i<n;i++){
        
        int leftMax=height[0];
        for(int j=0;j<i;j++){
            leftMax=max(leftMax,height[j]);
        }
        
        int rightMax=height[i+1];
        for(int j=i+1;j<n;j++){
            rightMax=max(rightMax,height[j]);
        }
        
        if(height[i] < leftMax && height[i] < rightMax){
            total +=min(leftMax,rightMax) - height[i];
        }
        
    }

    return total;
}


int trapRainWater_better(vector<int> &height,int n){
   
    int total=0;
    vector<int> prefix(n,0);
    vector<int> suffix(n,0);
    
    prefix[0] = height[0];
    for(int j=1;j<n;j++){
            prefix[j]=max(prefix[j-1],height[j]);
        }
        
    suffix[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--){
            suffix[j]=max(suffix[j+1],height[j]);
        }
    for(int i=0;i<n;i++){
        
        if(height[i] < prefix[i] && height[i] < suffix[i]){
            total +=min(prefix[i],suffix[i]) - height[i];
        }
        
    }

    return total;
} // O(3N) & O(2N)


int trapRainWater_optimal(vector<int> &height,int n){
   
    int total=0;
    int l = 0;
    int r=n-1;
    int leftMax=height[0];
    int rightMax=height[n-1];
    
    while(l<=r){
       
       leftMax=max(leftMax,height[l]);
       rightMax=max(rightMax,height[r]);
       
       if(leftMax < rightMax){
           total+=leftMax-height[l];
           l++;
       }
       else{
           total += rightMax - height[r];
           r--;
       }
    }
  
   
    return total;
} // O(N) & O(1);
int main() {
    
    vector<int> height = {4,2,0,3,2,5};
    int n=height.size();
    
    // cout<<trapRainWater_brute(height,n); // O(n x n) | O(1);
    cout<<trapRainWater_optimal(height,n);
    return 0;
}