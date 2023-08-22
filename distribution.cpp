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

void distribute(vector<int> &vec, int n) {
    for (int i{1}; i < vec.size(); i++) {
        for (int j{}; j < i && n > 0; j++) {
            --n;
            if (vec[j] < vec[i]) {
                vec[j]++;
            }
            else break;
        }
    }
}

int main() {
    vector<int> vec{3, 5, 8, 4, 6, 7, 4};
    int n = 3;

    cout << "Initial vector: " << endl;
    printVec(vec);

    sort(vec.begin(), vec.end());
    cout << "\nSorted vector: " << endl;
    printVec(vec);

    distribute(vec, n);
    cout << "\nDistributed vector: " << endl;
    printVec(vec);
}
