#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> repeatingAndMissing_brute(vector<int> nums, int n)
{

    int repeat = 0;
    int missing=0;

    for (int i = 1; i <= n; i++)
    { // 1 2 3 4 5
        int count = 0;

        for (int j = 0; j < n; j++)
        {

            if (i == nums[j])
            {
                count++;
            }
        }

         if(count==0) missing=i;

            if (count >= 2)
            {
                repeat = i;
            }
    }

    return {repeat,missing};
}


vector<int> repeatingAndMissing_better(vector<int> nums, int n){

    vector<int> hmap(n+1);  //O(n) - space

    hmap[0]={0};
    int missing=0;
    int repeat=0;

    for(int i=0;i<n;i++){
        hmap[nums[i]]++;
    }

    for(int i=1;i<=n;i++){

        if(hmap[i] == 0) missing=i;
        else if(hmap[i] >= 2) repeat=i;

    }

    return {missing,repeat};
}



vector<int> repeatingAndMissing_optimal_1(vector<int> nums, int n){

    int sumOfN=(n*(n+1))/2;
    int sumOfN_sqr=((n*(n+1)) * (2*n+1)) / 6;

    int sum=0,sqr_sum=0;

    for(int i=0;i<n;i++){
        sum=sum+nums[i];

        sqr_sum+=nums[i] * nums[i];
    }   


        int eq1=sumOfN - sum;           // x - y = eq1
        int eq2=sumOfN_sqr - sqr_sum;   // (x+y)(x-y) = eq2

        int eq3= eq2 / eq1;           // x + y = eq2 / (x-y)  =>>  x + y = eq3
        
        int x = (eq1 + eq3) / 2;                     // 2x = eq1 + eq3  => x = eq1 + eq2 / 2 

        int y =eq3 - x;

   
    // x - missing , y - repeating
    return  {x,y};
}
int main()
{

    vector<int> nums = {3, 2, 4, 1, 1};
    int n = nums.size();


    // for(auto &val:repeatingAndMissing_brute(nums,n)){
    //     cout<<val << " ";
    // }
    // for(auto &val:repeatingAndMissing_better(nums,n)){
    //     cout<<val << " ";
    // }
    // 
    for(auto &val:repeatingAndMissing_optimal_1(nums,n)){
        cout<<val << " ";
    }
    return 0;
}
