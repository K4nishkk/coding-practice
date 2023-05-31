// simple matrix multiplication
#include <iostream>
#include <vector>
#include <cmath>
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

    // overloading + operator (addition operator)
    Matrix operator+ (Matrix const &mat) {
        vector<vector<int>> m1{this -> m}, m2{mat.m};

        if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) {
            cout << "Matrix addition unsuccessful\n";
            return Matrix({});
        }

        int rows =static_cast<int>(m1.size());
        int columns = static_cast<int>(m1[0].size());

        vector<vector<int>> vec(rows, vector<int>(columns, 0));

        for (int i{}; i < rows; i++) 
            for (int j{}; j < columns; j++)
                vec[i][j] = m1[i][j] + m2[i][j];

        return Matrix(vec);
    }

    // function to return a matrix with 2 ^ n dimensions
    vector<vector<int>> dimension(vector<vector<int>> &vec) {
        int i = (vec.size() > vec[0].size() ? vec.size() : vec[0].size()); // choose which is more: rows or columns

        int n{1};
        while (i > pow(2, n))
            ++n;
            
        n = pow(2, n);

        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int j{}; j < vec.size(); j++)
            for (int k{}; k < vec[j].size(); k++)
                result[j][k] = vec[j][k];

        return result;
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
           {7, 8, 9, 3}},

        m2{{1, 2, 3, 7}, // matrix 2
           {4, 5, 6, 11},
           {7, 8, 9, 15}};

    Matrix mat1(m1), mat2(m2);
    Matrix mat3 = mat1 * mat2;
    cout << mat3 << endl;

    Matrix mat4 = mat1 + mat2;
    cout << mat4 << endl;

    Matrix mat5(mat1.dimension(mat1.m));
    cout << mat5 << endl;
}
