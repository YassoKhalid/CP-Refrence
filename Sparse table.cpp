// There is an east wind coming.
#include "bits/stdc++.h"

using namespace std;

#define int long long

const int N = 2e5, LOG = 20;

struct node {
    int val;
};
int logs[N];

struct SparseTable {
    vector<vector<node>> table;

    node single(int val) {
        node ret;
        ret.val = val;
        return ret;
    }

    node merge(node a, node b) {
        node ret;
        ret.val = min(a.val, b.val);
        return ret;
    }

    void build(vector<int> &a) {

        int n = (int) a.size();
        table = vector<vector<node>>(n + 1, vector<node>(LOG));

        for (int i = 0; i < n; i++) {
            table[i][0] = single(a[i]);
        }
        for (int j = 1; j <= logs[n]; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    node query(int l, int r) {
        int sz = logs[r - l + 1];
        return merge(table[l][sz], table[r - (1 << sz) + 1][sz]);
    }

    static void initLog() {
        logs[1] = 0;
        for (int i = 2; i < N; i++)
            logs[i] = logs[i >> 1] + 1;
    }
};


signed main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    SparseTable::initLog();
    return 0;
}
