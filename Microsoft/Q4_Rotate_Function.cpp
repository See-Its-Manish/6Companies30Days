// Ques:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void FIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int maxRotateFunction(vector<int>& nums) {
	int n = nums.size();
	int sum = 0, prev = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		prev += (nums[i] * i);
	}
	int ans = prev;
	for (int i = 1; i < n; i++) {
		int curr = prev + sum - n * nums[n - i];
		ans = max(ans, curr);
		prev = curr;
	}

	return ans;
}

int main() {
	FIO();

	int n;
	cin >> n;
	vector<int> nums(n);

	for (auto &i : nums) cin >> i;

	cout << maxRotateFunction(nums) << endl;
	return 0;
}