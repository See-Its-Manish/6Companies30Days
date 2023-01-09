// Ques:
#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
	int ans = 0;
	long long curr = 5;
	while (curr <= n) {
		ans += (n / curr);
		curr *= 5;
	}

	return ans;
}


void FIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	FIO();

	int n;
	cin >> n;

	cout << trailingZeroes(n) << endl;


	return 0;
}