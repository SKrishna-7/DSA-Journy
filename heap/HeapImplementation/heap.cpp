#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // ---------- Helper Functions ----------

    int getParent(int i) {
        return (i - 1) / 2;
    }

    int getLeft(int i) {
        return 2 * i + 1;
    }

    int getRight(int i) {
        return 2 * i + 2;
    }

    // ---------- Heapify Up ----------

    void heapifyUp(int current) {

        while (current > 0) {

            int parent = getParent(current);

            if (heap[current] <= heap[parent])
                break;

            swap(heap[current], heap[parent]);

            current = parent;
        }
    }

    // ---------- Heapify Down ----------

    void heapifyDown(int current, int heapSize) {

        while (true) {

            int largest = current;

            int left = getLeft(current);
            int right = getRight(current);

            if (left < heapSize && heap[left] > heap[largest])
                largest = left;

            if (right < heapSize && heap[right] > heap[largest])
                largest = right;

            if (largest == current)
                break;

            swap(heap[current], heap[largest]);

            current = largest;
        }
    }

public:

    // ---------- Constructors ----------

    MaxHeap() = default;

    MaxHeap(const vector<int>& arr) {

        heap = arr;
        buildHeap();
    }

    // ---------- Utility ----------

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    int top() const {

        if (heap.empty())
            throw runtime_error("Heap is empty");

        return heap[0];
    }

    // ---------- Insert ----------

    void insert(int value) {

        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    // ---------- Extract Max ----------

    int extractMax() {

        if (heap.empty())
            throw runtime_error("Heap is empty");

        int maxValue = heap[0];

        heap[0] = heap.back();

        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0, heap.size());

        return maxValue;
    }

    // ---------- Build Heap ----------

    void buildHeap() {

        int n = heap.size();

        for (int i = (n / 2) - 1; i >= 0; i--) {

            heapifyDown(i, n);
        }
    }

    // ---------- Heap Sort ----------

    vector<int> heapSort() {

        vector<int> sorted = heap;
        int n = sorted.size();

        // Build heap on the copied array
        for (int i = (n / 2) - 1; i >= 0; i--) {

            int current = i;

            while (true) {

                int largest = current;

                int left = 2 * current + 1;
                int right = 2 * current + 2;

                if (left < n && sorted[left] > sorted[largest])
                    largest = left;

                if (right < n && sorted[right] > sorted[largest])
                    largest = right;

                if (largest == current)
                    break;

                swap(sorted[current], sorted[largest]);

                current = largest;
            }
        }

        // Heap Sort
        for (int heapSize = n - 1; heapSize > 0; heapSize--) {

            swap(sorted[0], sorted[heapSize]);

            int current = 0;

            while (true) {

                int largest = current;

                int left = 2 * current + 1;
                int right = 2 * current + 2;

                if (left < heapSize && sorted[left] > sorted[largest])
                    largest = left;

                if (right < heapSize && sorted[right] > sorted[largest])
                    largest = right;

                if (largest == current)
                    break;

                swap(sorted[current], sorted[largest]);

                current = largest;
            }
        }

        return sorted;
    }

    // ---------- Print ----------

    void print() const {

        for (int x : heap)
            cout << x << " ";

        cout << '\n';
    }
};

int main() {

    MaxHeap h;

    h.insert(20);
    h.insert(40);
    h.insert(10);
    h.insert(60);
    h.insert(50);

    cout << "Heap: ";
    h.print();

    cout << "Top: " << h.top() << endl;

    cout << "Extract Max: " << h.extractMax() << endl;

    cout << "Heap After Extraction: ";
    h.print();

    vector<int> arr = {4, 32, 1, 2, 15, 9};

    MaxHeap heap(arr);

    cout << "Built Heap: ";
    heap.print();

    vector<int> sorted = heap.heapSort();

    cout << "Heap Sort: ";

    for (int x : sorted)
        cout << x << " ";

    cout << endl;

    return 0;
}