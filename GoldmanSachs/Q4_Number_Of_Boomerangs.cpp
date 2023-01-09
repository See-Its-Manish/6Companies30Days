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

long long getDist(vector<int> &a, vector<int> &b) {
	long long res = ((b[1] - a[1]) * (b[1] - a[1]) + (b[0] - a[0]) * (b[0] - a[0]));
	return res;
}

int numberOfBoomerangs(vector<vector<int>>& points) {
	int n = points.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		unordered_map<long long, long long> mp;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				long long dist = getDist(points[i], points[j]);
				mp[dist]++;
			}
		}

		for (auto &p : mp) ans += (p.second * (p.second - 1));
	}

	return ans;
}

int main() {
	FIO();

	int n;
	cin >> n;

	vector<vector<int>> points(n, vector<int>(2));

	for (int i = 0; i < n; i++) {
		cin >> points[i][0] >> points[i][1];
	}

	cout << numberOfBoomerangs(points) << endl;


	return 0;
}