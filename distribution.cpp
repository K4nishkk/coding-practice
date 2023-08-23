// Program to distribute items to containers
// already containing some number of items

// OBJECTIVE - distribute items evenly such that final
// difference between containers with max and min items is minimum

// CURRENT APPROACH - 
// → sort the array in ascending order
// → find the index i, till which all elements before i (0, 1, ... i - 1), can be assigned to vec[i]
//      without needing to subtract any number from them in order to get final vector
// → find number of items left to be added after the previous operation (n - items_distributed; n = initial number of items to be added) 
// → find same number of items need to be added to elements from index 0 - i ((n - items_distributed) / (i + 1) => avg of no. of items left; i + 1 = no. of containers)
// → find number of container that'll have one extra item ((n - items_distributed) % (i + 1) => remainder of no. of items left)
// → assign value of vec[0, 1, ... i] = vec[i] + avg of no. of items left + 1(for the first remainder items)

// TIME COMPLEXITY - O(nlogn) sorting + O(n - 1) difference_vector + O(n) distribution_vector = O(nlogn)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to display the vector
void printVec(vector<int> const &vec) {
    for (int i{}; i < vec.size(); i++)
        cout << vec[i] << "   ";
    cout << endl;
}

// to find difference between consequtive elements
vector<int> diff(vector<int> const &vec) {
    vector<int> diff_vec;
    diff_vec.resize(vec.size() - 1);

    for (int i{0}; i < vec.size() - 1; i++)
        diff_vec[i] = vec[i + 1] - vec[i];

    return diff_vec;
}

void distribute(vector<int> const &diff_vec, vector<int> &vec2, int n) {
    int items_distributed{}; // number of items already distributed (currently 0)

    int i;
    for (i = 0; i < diff_vec.size(); i++) {
        int k = (i + 1) * diff_vec[i]; // no. of items distributed to indices 0 - i in next iteration

        if (items_distributed + k <= n) // distribute only if sufficient items left
            items_distributed += k;

        else break;
    }

    int avg_items_left{(n - items_distributed) / (i + 1)}; // average item per container left
    int remainder{(n - items_distributed) % (i + 1)}; // remainder for division of items left (n - k) with no. of containers (i + 1)

    for (int j{}; j <= i; j++) // assign final values to items with indices 0 - i
        vec2[j] = vec2[i] + avg_items_left + (j < remainder ? 1 : 0);
}

int main() {
    vector<int> vec{12, 5, 9, 17, 22, 6, 4, 13};
    int n = 15;

    cout << "Initial vector:" << endl;
    printVec(vec);

    sort(vec.begin(), vec.end());
    cout << "\nSorted vector:" << endl;
    printVec(vec);

    vector<int> diff_vec;
    diff_vec.resize(vec.size() - 1);
    diff_vec = diff(vec);

    distribute(diff_vec, vec, n);
    cout << "\nDistributed vector:" << endl;
    printVec(vec);
}
