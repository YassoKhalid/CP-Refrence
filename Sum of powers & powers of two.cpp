// n^1+n^2+n^3+...n^k
int sum_pows(int n, int k) {
    if (!k)return 0;
    if (k & 1) return n * (1 + sum_pows(n, k - 1));
    int half = sum_pows(n, k / 2);
    half *= (1 + half - sum_pows(n, k / 2 - 1));
    return half;
}

// sum of pow of 2
int sum_pow(int n){

	return n*(n+1)*(2*n+1)/6;
}
