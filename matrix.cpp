// matrix class
#include <iostream>
#include <vector>
#include <array>
using namespace std;

// to convert into n x n matrix (n begin a mulitple of 2)
void dimensionalize(vector<vector<int>> &m0, vector<vector<int>> &m1) {
    int i = max(m0.size(), max(m1.size(), m1[0].size()));

    int n{1};

    while (n < i)
        n *= 2;

    while (m0.size() < n)
        m0.push_back({});
    while (m1.size() < n)
        m1.push_back({});

    for (int i{}; i < n; i++)
        while (m0[i].size() < n)
            m0[i].push_back(0);

    for (int i{}; i < n; i++)
        while (m1[i].size() < n)
            m1[i].push_back(0);
}

vector<vector<int>> undimensionalize(vector<vector<int>> vec, int rows, int columns) {
    vector<vector<int>> result(rows, vector<int>(columns, 0));

    for (int i{}; i < rows; i++)
        for (int j{}; j < columns; j++)
            result[i][j] = vec[i][j];

    return result;
}

// return 4 submatrices
array<vector<vector<int>>, 4> split(vector<vector<int>> m) {
    int n = m.size();

    vector<vector<int>> v0(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> v1(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> v2(n / 2, vector<int>(n / 2, 0));
    vector<vector<int>> v3(n / 2, vector<int>(n / 2, 0));

    for (int i{}; i < n / 2; i++) {
        for (int j{}; j < n / 2; j++) {
                v0[i][j] = m[i][j];
                v1[i][j] = m[i][j + n / 2];
                v2[i][j] = m[i + n / 2][j];
                v3[i][j] = m[i + n / 2][j + n / 2];
        }
    }

    return {v0, v1, v2, v3};
}

vector<vector<int>> combine(array<vector<vector<int>>, 4> v) {
    int n = v[0].size();
    vector<vector<int>> m(n * 2, vector<int>(n * 2, 0));

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
                m[i][j] = v[0][i][j];
                m[i][j + n] = v[1][i][j];
                m[i + n][j] = v[2][i][j];
                m[i + n][j + n] = v[3][i][j];
        }
    }

    return m;
}

vector<vector<int>> add(vector<vector<int>> m0, vector<vector<int>> m1) {
    int n = m0.size();

    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i{}; i < n; i++)
        for (int j{}; j < n; j++)
            result[i][j] = m0[i][j] + m1[i][j];

    return result;
}

vector<vector<int>> multiply(vector<vector<int>> m0, vector<vector<int>> m1) {
    int n = m0.size();

    if (n == 1)
        return {{m0[0][0] * m1[0][0]}};

    vector<vector<int>> vec(n, vector<int>(n, 0));

    array<vector<vector<int>>, 4> M0, M1;
    M0 = split(m0);
    M1 = split(m1);
    
    vector<vector<int>> a0{add(multiply(M0[0], M1[0]), multiply(M0[1], M1[2]))};
    vector<vector<int>> a1{add(multiply(M0[0], M1[1]), multiply(M0[1], M1[3]))};
    vector<vector<int>> a2{add(multiply(M0[2], M1[0]), multiply(M0[3], M1[2]))};
    vector<vector<int>> a3{add(multiply(M0[2], M1[1]), multiply(M0[3], M1[3]))};

    return combine({a0, a1, a2, a3});
}

class Matrix {
public:
    vector<vector<int>> m;

    // constructor
    explicit Matrix(vector<vector<int>> vec)
        : m{vec} {}

    Matrix operator* (Matrix const &mat);
    Matrix operator+ (Matrix const &mat);
};

// overloading multiplication operator (*)
Matrix Matrix::operator* (Matrix const &mat) {
    vector<vector<int>> m0{this -> m}, m1{mat.m};

    if (m0[0].size() != m1.size()) {
        cout << "Matrix multiplication unsuccessfull\n";
        return Matrix({});
    }

    int rows = static_cast<int>(m0.size());
    int columns = static_cast<int>(m1[0].size());
    int n = static_cast<int>(m1.size());

    vector<vector<int>> result;

    dimensionalize(m0, m1);
    result = multiply(m0, m1);

    result = undimensionalize(result, rows, columns);

    return Matrix(result);
}

// overloading addition operator (+)
Matrix Matrix::operator+ (Matrix const &mat) {
    vector<vector<int>> m0{this -> m}, m1{mat.m};

    if (m0.size() != m1.size() || m0[0].size() != m1[0].size()) {
        cout << "Matrix addition unsuccessful" << endl;
        return Matrix({});
    }
    
    int rows = static_cast<int>(m0.size());
    int columns = static_cast<int>(m1[0].size());

    vector<vector<int>> result(rows, vector<int>(columns, 0));

    for (int i{}; i < rows; i++)
        for (int j{}; j < columns; j++)
            result[i][j] = m0[i][j] + m1[i][j];

    return Matrix(result);
}

// overloading stream insertion operator (<<)
ostream &operator << (ostream &out, Matrix const &mat) {
    for (vector<int> vec : mat.m) {
        for (int element : vec)
            out << element << "   ";
        cout << endl;
    }

    return out;
}

int main() {
    vector<vector<int>> 
        m0{{1, 2, 3}, // matrix 1
           {4, 5, 6},
           {7, 8, 9}},

        m1{{1, 2}, // matrix 2
           {4, 5},
           {7, 8}};

    Matrix mat1(m0), mat2(m1);
    Matrix mat3 = mat1 * mat2;
    cout << mat3 << endl;
}
