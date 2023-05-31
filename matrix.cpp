// simple matrix multiplication
#include <iostream>
#include <vector>
using namespace std;

class Matrix{
public:
    vector<vector<int>> m;

    // constructor
    explicit Matrix(vector<vector<int>> vec)
        : m{vec} {}

    // overloading * operator
    Matrix operator* (Matrix const &mat) {
        vector<vector<int>> m1{this -> m}, m2{mat.m};

        if (m1[0].size() != m2.size()) {
            cout << "Matrix multiplication unsuccessfull\n";
            return Matrix({});
        }

        int rows =static_cast<int>(m1.size());
        int columns = static_cast<int>(m2[0].size());
        int n = static_cast<int>(m2.size());

        vector<vector<int>> vec(rows, vector<int>(columns, 0));

        for (int i{}; i < rows; i++)
            for (int j{}; j < columns; j++)
                for (int k{}; k < n; k++)
                    vec[i][j] += m1[i][k] * m2[k][j];
        
        return Matrix(vec);
    }
};

// overloading stream insertion operator
ostream & operator << (ostream &out, Matrix const &mat) {
    for (vector<int> vec : mat.m) {
        for (int element : vec)
            out << element << "   ";
        out << endl;
    }

    return out;
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

    Matrix mat1(m1), mat2(m2);
    Matrix mat3 = mat1 * mat2;
    cout << mat3;
}
