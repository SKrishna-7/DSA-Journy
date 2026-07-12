#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void heapify(vector<int>& nums, int current, int n){

        while(true){

            int largest = current;

            int left = 2*current+1;
            int right = 2*current+2;

            if(left < n && nums[left] > nums[largest])
                largest = left;

            if(right < n && nums[right] > nums[largest])
                largest = right;

            if(largest == current)
                break;

            swap(nums[current], nums[largest]);

            current = largest;
        }
    }

vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Build Max Heap
        for(int i = n/2 - 1; i >= 0; i--)
            heapify(nums, i, n);

        // Heap Sort
        for(int i = n-1; i > 0; i--){

            swap(nums[0], nums[i]);

            heapify(nums, 0, i);
        }

        return nums;
    }

int main(){

    vector<int> arr={6, 5, 3, 2, 8, 10, 9};

    cout<<endl;

    for(int i:sortArray(arr)){
        cout<<i << " ";

    }
    cout<<endl;
    return 0;
}



// Why Heap Sort?


// The problem requires O(N log N) time with the smallest possible extra space. 
//  Heap Sort satisfies both requirements because it builds a Max Heap in O(N) time and then performs N−1 heapify operations, 
// each taking O(log N).
//  Since all operations are done in-place, the extra space complexity is O(1).