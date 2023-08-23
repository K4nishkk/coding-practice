// Simplest program to distribute items to containers
// already containing some number of items

// OBJECTIVE - distribute items evenly such that
// difference between final max and min items is minimized

// CURRENT APPROACH - find container with min number of items
// & add difference of second lowest and lowest element or n, repeat until all items are distributed
// TIME COMPLEXITY - O(nm) n = no. of items to be distributed, m = size of array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> const &vec) {
    for (int i{}; i < vec.size(); i++) {
        cout << vec[i] << "   ";
    }
    cout << endl;
}

// to find difference between consequtive elements
vector<int> diff(vector<int> const &vec) {
    vector<int> diff_vec;
    diff_vec.resize(vec.size() - 1);
    for (int i{0}; i < vec.size() - 1; i++) {
        diff_vec[i] = vec[i + 1] - vec[i];
    }
    return diff_vec;
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

void add(vector<int> const &diff_vec, vector<int> &vec2, int n) {
    int k{}, i;
    for (i = 0; i < diff_vec.size(); i++) {
        if (k  + (i + 1) * diff_vec[i] <= n) {
            k += (i + 1) * diff_vec[i];
        }
        else break;
    }
    int avg_left{(n - k) / (i + 1)}, remainder{(n - k) % (i + 1)};
    for (int j{}; j <= i; j++) {
        vec2[j] = vec2[i] + avg_left + (j < remainder ? 1 : 0);
    }
    cout << "\ni: " << i << "   k: " << k << "   avg left: " << (n - k) / (i + 1) << "   remainder: " << (n - k) % (i + 1) 
        << "   n-k: " << n - k << endl;
}

int main() {
    vector<int> vec{12, 5, 9, 17, 22, 6, 4, 13};
    int n = 150;

    cout << "Initial vector:" << endl;
    printVec(vec);

    sort(vec.begin(), vec.end());
    cout << "\nSorted vector:" << endl;
    printVec(vec);
    
    vector<int> vec2{vec};

    vector<int> diff_vec;
    diff_vec.resize(vec.size() - 1);
    diff_vec = diff(vec);
    cout << "\nDifference of consequtive elements:" << endl;
    printVec(diff_vec);

    distribute(vec, n);
    cout << "\nDistributed vector:" << endl;
    printVec(vec);

    add(diff_vec, vec2, n);
    cout << "\nvec2:" << endl;
    printVec(vec2);
}
