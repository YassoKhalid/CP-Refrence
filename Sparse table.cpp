// There is an east wind coming.
#include "bits/stdc++.h"

using namespace std;

#define int long long

const int N = 2e5, LOG = 20;
int logs[N];

template<typename T>
struct SparseTable {
    vector<vector<T>> table;

    T merge(T a, T b) {}

    void build(vector<int> &a) {
        int n = (int) a.size();
        table = vector<vector<T>>(n + 1, vector<T>(logs[n] + 1));
        for (int i = 0; i < n; i++) {
            table[i][0] = T(a[i]);
        }
        for (int j = 1; j <= logs[n]; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) { // overlap o(1)
        int sz = logs[r - l + 1];
        return merge(table[l][sz], table[r - (1 << sz) + 1][sz]);
    }

    T queryNonOverlap(int l, int r) { // o(log n)
        T res;
        bool first = true;
        int log = (int) table[0].size();
        for (int i = log - 1; i >= 0; i--) {
            if (l + (1 << i) - 1 <= r) {
                if (first)res = table[l][i];
                else res = merge(res, table[l][i]);
                first = false;
                l += 1 << i;
            }
        }
        return res;
    }

    static void initLog() { // do not forget to call it before the code
        logs[1] = 0;
        for (int i = 2; i < N; i++)
            logs[i] = logs[i >> 1] + 1;
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    SparseTable<int>::initLog();
    
    return 0;
}
