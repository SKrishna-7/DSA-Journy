#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>

using namespace std;

//BruteForce
int calculateHours(vector<int> piles,int hour){
    
    int totalHour = 0;
  
    for(auto pile:piles){
        // totalHour += ceil((double)pile / (double)i);
        totalHour += (pile + hour -1) / 2; 
    }

    return totalHour;
        
}
int minEatingSpeed_Brute(vector<int> &piles, int h){

    int maxPiles = *max_element(piles.begin(), piles.end());

    for (int i = 1; i <= maxPiles; i++)
    {
        int totalHours=calculateHours(piles,i);
        if (totalHours <= h)
            return i;
    }
    return maxPiles;
}

int main()
{

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout<<minEatingSpeed_Brute(piles,h);

    return 0;
}