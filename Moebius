int moebius[N];
vector<int> primes(N), divs(N);
 
void sieve() {
    memset(moebius,-1, sizeof moebius);
    primes[1] = primes[0] = 1;
    for (int i = 2; i < N; i++) {
        if (primes[i] == 0) {
            moebius[i] = 1;
            for (int j = i * 2; j < N; j += i) {
                moebius[j] = (j % (i * i) == 0 ? 0 : -moebius[j]);
                primes[j] = 1;
            }
        }
    }
}
