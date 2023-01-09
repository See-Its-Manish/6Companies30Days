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


int maxPoints(vector<vector<int>>& points) {
	int n = points.size();
	unordered_map<double, int> fr;
	int ans = 0; double slope;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)  {
			if (points[j][0] - points[i][0] == 0) slope = INT_MAX;
			else {
				slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
			}
			fr[slope]++;
		}

		for (auto &p : fr) ans = max(ans, p.second);
		fr.clear();
	}

	return ans + 1;
}

int main() {
	FIO();

	int n;
	cin >> n;
	vector<vector<int>> points(n, vector<int>(2));

	for (auto &i : points) cin >> i[0] >> i[1];

	cout << maxPoints(points) << endl;

	return 0;
}