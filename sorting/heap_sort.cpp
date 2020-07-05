#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_LENGTH = 1000;

class Heap {
public:
    Heap() : count(0) {}

    // Max Heap
    void build_max_heap() {
        for (int parent = (count - 1) / 2; parent >= 0; parent--)
            max_heapify(parent, count);
    }
    void max_heapify(int parent, int length) {
        int left_child  = parent * 2 + 1;
        int right_child = left_child + 1;
        int max         = parent;

        if (left_child < length && array[left_child] > array[max])
            max = left_child;
        if (right_child < length && array[right_child] > array[max])
            max = right_child;

        if (max == parent)
            return;

        // Swaps parent with max
        int tmp       = array[parent];
        array[parent] = array[max];
        array[max]    = tmp;

        max_heapify(max, length);
    }

    // Min Heap
    void build_min_heap() {
        for (int parent = (count - 1) / 2; parent >= 0; parent--)
            min_heapify(parent, count);
    }
    void min_heapify(int parent, int length) {
        int left_child  = parent * 2 + 1;
        int right_child = left_child + 1;
        int min         = parent;

        if (left_child < length && array[left_child] < array[min])
            min = left_child;
        if (right_child < length && array[right_child] < array[min])
            min = right_child;

        if (min == parent)
            return;

        // Swaps parent with min
        int tmp       = array[parent];
        array[parent] = array[min];
        array[min]    = tmp;

        min_heapify(min, length);
    }

    // Sorting
    void ascending_sort() {
        build_max_heap();

        for (int i = count - 1; i >= 0; i--) {
            // Swaps the first element (max element) with the last one (index i)
            int tmp  = array[0];
            array[0] = array[i];
            array[i] = tmp;

            max_heapify(0, i);
        }
    }
    void descending_sort() {
        build_min_heap();

        for (int i = count - 1; i >= 0; i--) {
            // Swaps the first element (min element) with the last one (index i)
            int tmp  = array[0];
            array[0] = array[i];
            array[i] = tmp;

            min_heapify(0, i);
        }
    }

    // Input/Output
    void set_values() {
        int n;
        while (cin >> n, n != -1 && count < MAX_LENGTH)
            array[count++] = n;
    }
    void print() const {
        for (int i = 0; i < count; i++)
            cout << array[i] << " ";
        cout << endl << endl;
    }

private:
    int array[MAX_LENGTH];
    int count;
};

int main() {
    Heap heap;

    heap.set_values(); // Input ends with -1

    // Builds a max heap
    heap.build_max_heap();
    cout << "[Max Heap]" << endl;
    heap.print();

    // Builds a min heap
    heap.build_min_heap();
    cout << "[Min Heap]" << endl;
    heap.print();

    // Sorts in ascending order
    heap.ascending_sort();
    cout << "[Ascending Order]" << endl;
    heap.print();

    // Sorts in descending order
    heap.descending_sort();
    cout << "[Descending Order]" << endl;
    heap.print();

    return 0;
}