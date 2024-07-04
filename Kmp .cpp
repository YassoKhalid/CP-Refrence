struct KMP {
	string pattern;
	vector<int> longestPrefix;
	KMP(string& str) :pattern(str) {
		failure_function();
	}
	int fail(int k, char nxt) {
		while (k > 0 && pattern[k] != nxt)
			k = longestPrefix[k - 1];
		if (nxt == pattern[k]) k++;
		return k;
	}
	void failure_function() {
		int n = pattern.size();
		longestPrefix = vector<int>(n);
		for (int i = 1, k = 0; i < n; i++)
			longestPrefix[i] = k = fail(k, pattern[i]);
	}
	void match(const string& str) {
		int n = str.size();
		int m = pattern.size();
		for (int i = 0, k = 0; i < n; i++) {
			k = fail(k, str[i]);
			if (k == m) {
				cout << i - m + 1 << endl; //0-based
				k = longestPrefix[k - 1]; // if you want next match
			}
		}
	}
};
