#include<iostream>
#include <vector>


using namespace std;

int main(){

    vector<int> nums={3,1,-2,-5,2,-4};
    int n= nums.size();

    vector<int> pos;
    vector<int> neg;

    for(auto &num : nums){
        if(num > 0) pos.push_back(num);
        else neg.push_back(num);
    }
    
    for(int i=0;i<n;i++){

       if( i % 2 ==0){
            nums[i] = pos[i / 2];
       }
       else{
        nums[i] = neg[i/2];
       }

    }

    for(auto i:nums){
        cout<<i<<endl;
    }
    return 0;
}