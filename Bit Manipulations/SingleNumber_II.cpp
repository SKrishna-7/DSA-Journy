#include<iostream>
#include<vector>

using namespace std;

//Brute - Use nested loop
// Better - Use hashmap

// Better with Bit
int singleNumber_better(vector<int>& nums) {
        
        int ans=0;

        for(int bitIndex=0;bitIndex<32;bitIndex++){

        int count=0;
          for(int i=0;i<nums.size();i++){

            if(nums[i] & (1 << bitIndex)) {
                count++;
                }

          }  
            if(count % 3 == 1){
                ans = ans | (1 << bitIndex);
            }
        }

        return ans;
    } //       O( N x 32) | Sc - O(1)

// Better -

int singleNumber(vector<int>& nums) {
        
        int ans=0;
        int n= nums.size();

        sort(nums.begin(),nums.end());

        for(int i=1;i < n;i+=3){

            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }

        return nums[n-1];
    }
    

// Optimal

 int singleNumber(vector<int>& nums) {
        
       int ones=0;
       int twos=0;


        for(int i=0;i<nums.size();i++){

            ones = (ones ^ nums[i]) & ~(twos);
            twos = (twos ^ nums[i]) & ~(ones);
        }

        return ones;
    }
int main(){


    return 0;
}