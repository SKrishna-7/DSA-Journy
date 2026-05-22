#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int bestTimeToBuyandSell(vector<int> &prices){
        

    int minPrice=INT_MAX;
    int maxProfit=0;

    for(auto &price:prices){

        minPrice=min(minPrice,price);
        maxProfit=max(maxProfit,price-minPrice);
    }


    return maxProfit;
}

int bestTimeToBuyandSell_1(vector<int>& prices) {
        
        int minPrice=INT_MAX;
        int maxProfit=0;

        for(auto price:prices){

            if(price < minPrice){
                minPrice=price;
            }
            
            else if(price-minPrice > maxProfit){
                maxProfit=price-minPrice;
            }
        }

        return maxProfit;
    }

int main(){


    vector<int> nums={7,1,5,3,6,4};

    cout<<bestTimeToBuyandSell(nums);


    return 0;
}