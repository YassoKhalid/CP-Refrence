const int N = 1e8;
bool isPrime[N + 1];
vector<int> prime;
void sieve() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i <= N; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i <= N; i += 2)
		if (isPrime[i])
			for (int j = i * i; j <= N; j += i + i)
				isPrime[j] = false;
	for (int i = 1; i <= N; i++)
		if (isPrime[i])
			prime.push_back(i);
}
map<int,int>mp;
void Prime_Factors_Faster(int n){
	int idx = 0;
	while (idx < primes.size() && primes[idx] * primes[idx] <= n){
		if (n % primes[idx] == 0)
            mp[primes[idx]]++;
		while (n % primes[idx] == 0){
			n /= primes[idx];
		}
		++idx;
	}
	if(n>1)
        mp[n]++;
}
// spf
vector<int>spf(N+1);
void seive() {
    iota(spf.begin(), spf.end(),0);
    for (int32_t i = 4; i <= N; i += 2) {
        spf[i] = 2;
    }
    for (int32_t i = 3; 1ll * i * i <= N; i+=2) {
        if (spf[i] == i) {
            for (ll j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
// linear sieve lpf nlog logn
const int N = 1e7;
int lpf[N + 1];
vector<int> prime;
void sieve() {
	for (int i = 2; i <= N; i++) {
		if (lpf[i] == 0) {
			lpf[i] = i;
			prime.push_back(i);
		}
		for (int j : prime) {
			if (j > lpf[i] || 1LL * i * j > N)break;
			lpf[i * j] = j;
		}
	}
}


