
int add(int a, int b) { return ((a % mod) + (b % mod) +  mod) % mod; }
 
int mul(int a, int b) { return (a % mod) * (b % mod) % mod; }

int sub(int a, int b){ return (((a+mod)%mod-(b+mod)%mod)%mod+mod)%mod;}
//Fast power


int fp(int x, int y, int MOD = 1e9 + 7) {
    if (y == 0) return 1;
    if (y == 1) return x % MOD;
    int cur = fp(x, y >> 1, MOD);
    return (((cur * cur) % MOD) * fp(x, y & 1, MOD)) % MOD;
}

int fp(int n, int p) {

    if (p == 0)return 1;
    int ret = fp(n, p >> 1LL);
    ret *= ret;
    ret %= mod;
    if (p & 1)ret *= n;
    ret %= mod;
    return ret;
}


//Sum of powers
// return a ^ 1 + a ^ 2 + a ^ 3 + .... a ^ k
ll sumPower(ll a, ll k, int mod) {
	if (k == 1) return a % mod;
	ll half = sumPower(a, k / 2, mod);
	ll p = half * power(a, k / 2, mod) % mod;
	p = (p + half) % mod;
	if (k & 1) p = (p + power(a, k, mod)) % mod;
	return p;
}


//Mod Inverse
ll modInverse(ll b, ll mod) { // if mod is Prime
    return power(b, mod - 2, mod);
}
ll modInverse(ll b, ll mod) { // if mod is not Prime,gcd(a,b) must be equal 1
    return power(b, phi_function(mod) - 1, mod);
}

//(a^n)%p=result , return n
// (a^n)%p=result, return minimum n
int getPower(int a, int result, int mod) {
	int sq = sqrt(mod);
	map<int, int> mp;
	ll r = 1;
	for (int i = 0; i < sq; i++) {
		if (mp.find(r) == mp.end())
			mp[r] = i;
		r = (r * a) % mod;
	}
	ll tmp = modInverse(r, mod);
	ll cur = result;
	for (int i = 0; i <= mod; i += sq) {
		if (mp.find(cur) != mp.end())
			return i + mp[cur];
		cur = (cur * tmp) % mod;//val/(a^sq)
	}
	return INF;
}


// Returns minimum x for which a ^ x % m = b % m.
// a,m not not coprime
int getPower(int a, int b, int m) {
	a %= m, b %= m;
	int k = 1, add = 0, g;
	while ((g = __gcd(a, m)) > 1) {
		if (b == k)
			return add;
		if (b % g)
			return -1;
		b /= g, m /= g, ++add;
		k = (k * 1ll * a / g) % m;
	}

	int n = sqrt(m) + 1;
	int an = 1;
	for (int i = 0; i < n; ++i)
		an = (an * 1ll * a) % m;

	unordered_map<int, int> vals;
	for (int q = 0, cur = b; q <= n; ++q) {
		vals[cur] = q;
		cur = (cur * 1ll * a) % m;
	}

	for (int p = 1, cur = k; p <= n; ++p) {
		cur = (cur * 1ll * an) % m;
		if (vals.count(cur)) {
			int ans = n * p - vals[cur] + add;
			return ans;
		}
	}
	return -1;
}

