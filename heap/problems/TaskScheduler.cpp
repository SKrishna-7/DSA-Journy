#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int main(){

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int interval =2;
    
    int n = tasks.size();

    vector<int> freq(26,0);
    vector<int> next_available(26,0);


    for(int i=0;i<n;i++){
        freq[tasks[i] - 'A']++;
    }

    int remaining_tasks = tasks.size();
    int current_time =0;

    
    while(remaining_tasks > 0){

        int best_task = -1;
        int max_count = 0;

        for(int i=0;i<26;i++){
            
            if(freq[i] > 0 && next_available[i] <= current_time){
               
                if(freq[i] > max_count){

                    max_count = freq[i];
                    best_task = i;
                }
            }
        }

        if(best_task != -1){

            freq[best_task]--;
            next_available[best_task] = current_time + interval + 1;
            remaining_tasks--;

        }

        current_time++;
    }


    cout<<current_time;
    return 0;
}