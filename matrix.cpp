// simple matrix multiplication
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mulitply(vector<vector<int>> &m1, vector<vector<int>> &m2) {
    // check compatibility
    if (m1[0].size() != m2.size()) { // 1st matrix column == 2nd matrix rows
        cout << "matrix multiplication not possible\n";
        return {};
    }

    int n{static_cast<int>(m2.size())};

    int rows{static_cast<int>(m1.size())}, columns{static_cast<int>(m2[0].size())}; // dimensions of final matrix

    vector<vector<int>> vec(rows, vector<int>(columns, 0));

    for (int i{}; i < rows; i++) {
        for (int j{}; j < columns; j++) {
            for (int k{}; k < n; k++) {
                vec[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return vec;
}

int main() {
    vector<vector<int>> 
        m1{{1, 2, 3, 1}, // matrix 1
           {4, 5, 6, 2},
           {7, 8, 9, 3},
           {7, 8, 9, 3}},

        m2{{1, 2, 3}, // matrix 2
           {4, 5, 6},
           {7, 8, 9},
           {7, 8, 9}};

    vector<vector<int>> vec = mulitply(m1, m2);

    for (vector<int> rows : vec) {
        for (int element : rows) {
            cout << element << "   ";
        }
        cout << endl;
    }
}
