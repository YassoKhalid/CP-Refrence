struct Mat {
    int n, m;
    vector<vector<int> > mat;

    Mat() {}

    Mat(int _n, int _m) {
        n = _n;
        m = _m;
        mat = vector<vector<int>>(n, vector<int>(m));
    }

    Mat(int _n) {
        n = _n;
        m = _n;
        mat = vector<vector<int>>(n, vector<int>(m));
    }

    Mat(vector<vector<int> > v) {
        mat = v;
        n = (int) v.size();
        m = (int) v[0].size();
    }

    void id(int _n) {
        mat = vector<vector<int>>(_n, vector<int>(_n));
        for (int i = 0; i < _n; i++)
            mat[i][i] = 1;
    }

    Mat operator*(Mat b) {
        Mat ans(b.n);
        for (int i = 0; i < b.n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < b.m; k++) {
                    ans.mat[i][j] += mat[i][k] * b.mat[k][j];
                    // ans.mat[i][j] %= mod;
                }
        return ans;
    }

    Mat operator+(Mat b) {
        Mat ans(b.n);
        for (int i = 0; i < b.n; i++)
            for (int j = 0; j < b.m; j++)
                ans.mat[i][j] = mat[i][j] + b.mat[i][j];
        return ans;
    }

    Mat exp(Mat a, int b) {
        Mat ans = a;
        ans.id(a.n);
        while (b) {
            if (b & 1) ans = ans * a;
            a = a * a;
            b >>= 1;
        }
        return ans;
    }

    Mat operator^(int x) {
        Mat ans = *this;
        ans.id(ans.n);
        Mat res = *this;
        while (x > 0) {
            if (x & 1) {
                ans = res * ans;
            }
            res = res * res;
            x /= 2;
        }
        return ans;
    }
};
