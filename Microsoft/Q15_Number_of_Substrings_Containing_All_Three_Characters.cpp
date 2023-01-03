// Ques:
#include<bits/stdc++.h>
using namespace std;

void FIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int numberOfSubstrings(string s) {
	int n = s.size();

	vector<int> a(n), b(n), c(n);

	a[n - 1] = ((s[n - 1] == 'a' ) ? n - 1 : INT_MAX);
	b[n - 1] = ((s[n - 1] == 'b' ) ? n - 1 : INT_MAX);
	c[n - 1] = ((s[n - 1] == 'c' ) ? n - 1 : INT_MAX);

	for (int i = n - 2; i >= 0; i--) {
		a[i] = ((s[i] == 'a') ? i : a[i + 1]);
		b[i] = ((s[i] == 'b') ? i : b[i + 1]);
		c[i] = ((s[i] == 'c') ? i : c[i + 1]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int last = max({a[i], b[i], c[i]});
		if (last != INT_MAX)
			ans += n - last;
	}

	return ans;
}

int main() {
	FIO();

	int n;
	cin >> n;
	string s;
	cin >> s;

	cout << numberOfSubstrings(s) << endl;



	return 0;
}