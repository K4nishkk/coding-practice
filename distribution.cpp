// Simplest program to distribute items to containers
// already containing some number of items

// OBJECTIVE - distribute items evenly such that
// difference between final max and min items is minimized

// CURRENT APPROACH - find container with min number of items
// & add an items to it, repeat until all items are distributed
// TIME COMPLEXITY - O(nm) n = no. of items to be distributed, m = size of array

#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> const &vec) {
    for (int i{}; i < vec.size(); i++) {
        cout << vec[i] << "   ";
    }
    cout << endl;
}

// returns index of minimum element
int min(vector<int> &vec) {
    int min_index{};
    for (int i{1}; i < vec.size(); i++) { // runs m - 1 times (m = no. of elements in array)
        if (vec[i] < vec[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void distribute(vector<int> &vec, int n) {
    int i{};
    while (n > 0) { // runs n times (n = no. of items to be distributed)
        i = min(vec);
        vec[i]++;
        n--;
    }
}

int main() {
    vector<int> vec{3, 5, 8, 4, 6, 7, 4};
    int n = 100;

    cout << "Initial vector: " << endl;
    printVec(vec);

    distribute(vec, n);
    cout << "\nDistributed vector: " << endl;
    printVec(vec);
}
