#include<bits/stdc++.h>

using namespace std;

struct matrix {
    int n, m, k;
    vector<vector<vector<int>>> mat;

    matrix() {

    }

    matrix(int _n, int _m, int _k) {
        n = _n;
        m = _m;
        k = _k;
        mat.resize(n, vector<vector<int>>(m, vector<int>(k)));
    }

    void setIdx(int i, int j, int z, int val) {
        if (i < 0 || i > n || j < 0 || j > m || z < 0 || z > k)return;
        mat[i][j][z] = val;
    }

    int getIdx(int i, int j, int z) {
        if (i < 0 || i > n || j < 0 || j > m || z < 0 || z > k) return -1;
        return mat[i][j][z];
    }

};

struct matrixFlatten {
    vector<int> vec;
    int n, m, k;

    matrixFlatten() {

    }

    int convertIdx(int i, int j, int z) {
        return i * m * k + j * k + z;
    }

    matrixFlatten(matrix mat) {
        int size = mat.n * mat.m * mat.k;
        n = mat.n;
        m = mat.m;
        k = mat.k;
        vec.resize(size);
        for (int i = 0; i < mat.n; i++) {
            for (int j = 0; j < mat.m; j++) {
                for (int z = 0; z < mat.k; z++) {
                    vec[convertIdx(i, j, z)] = mat.getIdx(i, j, z);
                }
            }
        }
    }

    void setIdx(int i, int j, int z, int val) {
        if (i < 0 || i > n || j < 0 || j > m || z < 0 || z > k)return;
        vec[convertIdx(i, j, z)] = val;
    }

    int getIdx(int i, int j, int z) {
        if (i < 0 || i > n || j < 0 || j > m || z < 0 || z > k) return -1;
        return vec[convertIdx(i, j, z)];
    }

    void print() {
        cout << "Matrix Flatten values: \n";
        for (auto v:vec)cout << v << " ";
        cout << "\n";
    }
};

int main() {
    int n, m, k;
    cout << "Enter the dimensions of the 3D matrix: \n";
    cin >> n >> m >> k;
    while (n <= 0 || m <= 0 || k <= 0) {
        cout << "Invalid dimensions\n";
        cout << "Enter the dimensions of the 3D matrix: \n";
        cin >> n >> m >> k;
    }
    matrix mat(n, m, k);
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < k; z++) {
                cout << "Enter value in the cell " << i + 1 << " " << j + 1 << " " << z + 1 << "\n";
                cin >> val;
                mat.setIdx(i, j, z, val);
            }
        }
    }
    matrixFlatten matFlat(mat);
    matFlat.print();
}