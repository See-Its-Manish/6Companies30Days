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


string getHint(string secret, string guess) {

	int n = secret.size();

	vector<int> hsh(10, 0);

	for (int i = 0; i < n; i++) {
		hsh[secret[i] - '0']++;
	}

	// for (int i = 0; i < 10; i++) cout << hsh[i] << " ";
	// cout << endl;

	int bulls = 0, cows = 0;
	for (int i = 0; i < n; i++) {

		if (secret[i] == guess[i]) {
			int idx = guess[i] - '0';
			if (hsh[idx] == 0) {
				bulls++, cows--;
			}
			else {
				bulls++, hsh[idx]--;
			}
		}
		else {
			if (hsh[guess[i] - '0'] > 0) cows++, hsh[guess[i] - '0']--;
		}
	}

	string ans = to_string(bulls) + "A" + to_string(cows) + "B";

	return ans;
}

int main() {
	FIO();

	int n;
	cin >> n;
	string secret, guess;
	cin >> secret >> guess;

	string ans = getHint(secret, guess);
	cout << ans << endl;

	return 0;
}