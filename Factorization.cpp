
vector<int> divs(int n) {
    vector<int> divs;
    divs.emplace_back(1);
    if (n != 1)
        divs.emplace_back(n);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divs.emplace_back(i);
            if (n / i != i)divs.emplace_back(n / i);
        }
    }
    return divs;
}
