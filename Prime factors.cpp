// return number of Divisors(n) using prime factorization
int numOfDivisors(unordered_map<int32_t, int32_t> mp) {
    int cnt = 1;
    for (auto it: mp) cnt *= (1ll * it.second + 1);
    return cnt;
}

// return sum of Divisors(n) using prime factorization
ll sumOfDivisors(primeFactors mp) {
	ll sum = 1;
	for (auto it : mp) sum *= sumPower(it.first, it.second);
	return sum;
}
// power of a prime factor
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}
// prime factorization

vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> ret;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0)cnt++, n /= i;
        if (cnt)ret.emplace_back(i, cnt);
    }
    if (n > 1)ret.emplace_back(n, 1);
    return ret;
}

// generate divisors using prime factors
vector<int> get(int n) {
    vector<pair<int, int>> primes = primeFactorization(n);
    vector<int> divs = {1};
    for (auto &it: primes) {
        int prime = it.first;
        int po = it.second;
        int current_size = divs.size();
        for (int i = 0; i < current_size; ++i) {
            int divisor = divs[i];
            int power = 1;
            for (int j = 1; j <= po; ++j) {
                power *= prime;
                divs.push_back(divisor * power);
            }
        }
    }
    return divs;
}
// optmizied prime factorization
unordered_map<int32_t, int32_t> getFactorization(int x) {
    unordered_map<int32_t, int32_t> ret;
    while (x != 1) {
        ret[spf[x]]++;
        x = x / spf[x];
    }
    return ret;
}
