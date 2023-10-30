#include <iostream>
#include <vector>

using namespace std;

struct Element {
    int r;
    int c;
    int v;
};

struct MatrixCSR {
    vector<int> v;
    vector<int> c;
    vector<int> rp;
};

MatrixCSR initSM(vector<vector<int> > m) {
    MatrixCSR r;
    int n = m.size();
    int p = m[0].size();
    r.rp.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            if (m[i][j] != 0) {
                r.v.push_back(m[i][j]);
                r.c.push_back(j);
            }
        }
        r.rp.push_back(r.v.size());
    }

    return r;
}

MatrixCSR multSM(const MatrixCSR& a, const MatrixCSR& b, int n) {
    MatrixCSR r;
    r.rp.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dp = 0;
            int sA = a.rp[i];
            int eA = a.rp[i + 1];
            int sB = b.rp[j];
            int eB = b.rp[j + 1];
            int kA = sA;
            int kB = sB;

            while (kA < eA && kB < eB) {
                if (a.c[kA] == b.c[kB]) {
                    dp += a.v[kA] * b.v[kB];
                    kA++;
                    kB++;
                } else if (a.c[kA] < b.c[kB]) {
                    kA++;
                } else {
                    kB++;
                }
            }

            if (dp != 0) {
                r.v.push_back(dp);
                r.c.push_back(j);
            }
        }
        r.rp.push_back(r.v.size());
    }

    return r;
}

void dspSM(const MatrixCSR& m) {
    int n = m.rp.size() - 1;
    for (int i = 0; i < n; i++) {
        cout << "Row " << i << ": ";
        for (int j = m.rp[i]; j < m.rp[i + 1]; j++) {
            cout << "(" << i << ", " << m.c[j] << "): " << m.v[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > m1(4, vector<int>(5));
    m1[0][2] = 3;
    m1[0][4] = 4;
    m1[1][2] = 5;
    m1[1][3] = 7;
    m1[3][1] = 2;
    m1[3][2] = 6;

    vector<vector<int> > m2(5, vector<int>(4));
    m2[1][3] = 8;
    m2[2][2] = 9;
    m2[3][1] = 7;
    m2[4][0] = 5;

    MatrixCSR sm1 = initSM(m1);
    MatrixCSR sm2 = initSM(m2);

    cout << "Sparse Matrix 1 (CSR format):" << endl;
    dspSM(sm1);

    cout << "Sparse Matrix 2 (CSR format):" << endl;
    dspSM(sm2);

    if (sm1.c[sm1.c.size() - 1] != sm2.rp.size() - 1) {
        cout << "Matrix multiplication is not possible. Column count of A is not equal to the row count of B." << endl;
    } else {
        MatrixCSR result = multSM(sm1, sm2, m1.size());

        cout << "Result of matrix multiplication (CSR format):" << endl;
        dspSM(result);
    }

    return 0;
}
