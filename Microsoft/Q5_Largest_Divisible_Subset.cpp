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

vector<int> largestDivisibleSubset(vector<int>& nums) {

	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<int> dp(n, 1), hsh(n);
	for (int i = 0; i < n; i++) hsh[i] = i;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if ((nums[i] % nums[j]) == 0 and dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				hsh[i] = j;
			}
		}
	}

	int maxidx = 0;
	for (int i = 1; i < n; i++) {
		if (dp[maxidx] < dp[i]) {
			maxidx = i;
		}
	}

	vector<int> ans;
	int curr = maxidx;
	while (1) {
		ans.push_back(nums[curr]);
		if (curr != hsh[curr]) curr = hsh[curr];
		else break;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}
int main() {
	FIO();

	int n;
	cin >> n;
	vector<int> nums(n);

	for (auto &i : nums) cin >> i;

	vector<int> ans = largestDivisibleSubset(nums);

	for (auto &i : ans) cout << i << " ";
	cout << endl;

	return 0;
}