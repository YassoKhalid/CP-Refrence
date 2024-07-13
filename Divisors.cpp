vector<int> divs[N];
void pre(){
for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
}
