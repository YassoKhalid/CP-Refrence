
//Sum Sequence
//return sum of sequence a, a+x , a+2x .... b
ll sumSequence(ll a, ll b, ll x) {
	a = ((a + x - 1) / x) * x;
	b = (b / x) * x;
	return (b + a) * (b - a + x) / (2 * x);
}


//Sum Range Divisors
// return sum of divisors for all number from 1 to n //O(n)
ll sumRangeDivisors(int n) {
	ll ans = 0;
	for (int x = 1; x <= n; x++)
		ans += (n / x) * x;
	return ans;
}
// calc 1e9 in 42ms,can calc more but need big integer
ll sumRangeDivisors(ll x) {
	ll ans = 0, left = 1, right;
	for (; left <= x; left = right + 1) {
		right = x / (x / left);
		ans += (x / left) * (left + right) * (right - left + 1) / 2;
	}
	return ans;
}
