#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
    queue<long long> q;
    int i = 0, j = 0;
    vector<long long> ans;

    while (j < N) {
        if (A[j] < 0) {
            q.push(A[j]);
        }

        if (j - i + 1 < K) {
            j++;
        } else {
            if (!q.empty())
                ans.push_back(q.front());
            else
                ans.push_back(0);

            if (A[i] < 0) {
                q.pop();
            }

            i++;
            j++;
        }
    }

    return ans;
}

int main() {
    long long a[] = {-2, -3, -4, -5, -6, -7, -8};
    long long n = sizeof(a) / sizeof(a[0]); // Corrected the size calculation
    long long k = 4;

    vector<long long> result = printFirstNegativeInteger(a, n, k);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
