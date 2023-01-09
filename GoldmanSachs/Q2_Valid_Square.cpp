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

long long getDistance(vector<int> &p1, vector<int> &p2) {
	return ((p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]));
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
	unordered_map<long long, long long> mp;
	vector<vector<int>> v = {p1, p2, p3, p4};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) mp[getDistance(v[i], v[j])];
		}
	}

	return (mp.count(0) == 0 and mp.size() == 2);
}

int main() {
	FIO();

	vector<int> p1(2), p2(2), p3(2), p4(2);

	cin >> p1[0] >> p1[1];
	cin >> p2[0] >> p2[1];
	cin >> p3[0] >> p3[1];
	cin >> p4[0] >> p4[1];

	cout << validSquare(p1, p2, p3, p4) << endl;

	return 0;
}