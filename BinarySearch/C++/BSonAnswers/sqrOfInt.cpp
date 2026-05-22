#include<iostream>
#include<vector>

using namespace std;

int sqrRoot_brute(int n){

    int ans=1;

    for(int i=1;i<=n;i++) {
        if(i*i <= n) ans = i;

        else break;
    }
    return ans;

}


int sqrRoot_optimal(int n){

    int low=1;
    int high=n;

    int ans=1;

    while(low<=high){
        
        int mid=low+(high-low) / 2;

        if(mid*mid <= n) {
            ans=mid;
            low=mid+1;

}
        else high=mid-1;

    }
    return ans;

}

int main(){

    int n=38;
    
    // cout<<sqrRoot_brute(n)<<endl;
    cout<<sqrRoot_optimal(n)<<endl;

    return 0;
}