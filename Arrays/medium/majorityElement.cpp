#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int majorityElement(vector <int> arr){

        int count=0;
        int el;

        for(int i=0;i<arr.size();i++){

            if(count == 0){
                count=1;
                el=arr[i];
            }

            else if(arr[i] == el) count++;

            else count--;
        }

        int cnt=0;

        for(auto i:arr){
            if (i == el){
                cnt++;
            }
        }
        
        if(cnt > (arr.size()/2)){
            return el;
        }

        return -1;

}

int main(){

    vector<int> arr= {2,2,1,1,1,1,2};  
    int n=arr.size();
    

    cout<< majorityElement(arr);

    return 0;
}
