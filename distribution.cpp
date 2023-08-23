// Simplest program to distribute items to containers
// already containing some number of items

// OBJECTIVE - distribute items evenly such that
// difference between final max and min items is minimized

// CURRENT APPROACH - find container with min number of items
// & add difference of second lowest and lowest element or n, repeat until all items are distributed
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

// returns min_index and difference between second and first min element
vector<int> min(vector<int> &vec) {
    int min_index{}, second_min_index{};
    for (int i{1}; i < vec.size(); i++) { // runs m - 1 times (m = no. of elements in array)
        if (vec[i] < vec[min_index]) {
            second_min_index = min_index;
            min_index = i;
        }
    }
    return {min_index, vec[second_min_index] - vec[min_index]};
}

void distribute(vector<int> &vec, int n) {
    int min_index{}, diff{};
    while (n > 0) {
        vector<int> v = min(vec);
        min_index = v[0];
        diff = v[1];
        
        if (diff == 0) { // otherwise infinite loop for diff == 0
            vec[min_index]++;
            n--;
        }
        else if (n > diff) {
            vec[min_index] += diff;
            n -= diff;
        }
        else {
            vec[min_index] += n;
            break;
        }
    }
}

int main() {
    vector<int> vec{3, 5, 8, 4, 6, 7, 4};
    int n = 16;

    cout << "Initial vector: " << endl;
    printVec(vec);

    distribute(vec, n);
    cout << "\nDistributed vector: " << endl;
    printVec(vec);
}
