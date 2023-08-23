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
    for (int i{1}; i < vec.size(); i++) {
        if (vec[i] < vec[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void distribute(vector<int> &vec, int n) {
    int i{};
    while (n > 0) {
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
