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

#define M 1000000009
#define ll long long

ll add(ll a, ll b) {
	return ((a % M) + (b % M)) % M;
}

vector<list<pair<int, int>>> gr; // <node,dist>

void buildgraph(int n, vector<vector<int>> &roads) {
	gr.clear();
	gr.resize(n);

	for (int i = 0; i < roads.size(); i++) {
		gr[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
		gr[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
	}
}

int countPaths(int n, vector<vector<int>>& roads) {
	buildgraph(n, roads);

	// Now I have to apply dijkstra's algorithm
	vector<ll> dis(n, LLONG_MAX);
	vector<ll> ways(n, 0);
	dis[0] = 0, ways[0] = 1;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	//<dis,node>
	pq.push({0, 0});

	while (!pq.empty()) {
		pair<ll, ll> element = pq.top();
		pq.pop();
		ll node = element.second;
		ll dist = element.first;

		for (auto &neigh : gr[node]) {
			if (dist + neigh.second < dis[neigh.first]) {
				dis[neigh.first] =  dist + neigh.second;
				pq.push({dis[neigh.first], neigh.first});
				ways[neigh.first] = ways[node];
			}
			else if (dist + neigh.second == dis[neigh.first]) {
				ways[neigh.first] = add(ways[neigh.first], ways[node]);
			}
		}
	}


	return ways[n - 1];
}

int main() {
	FIO();

	int n;
	cin >> n;

	int e;
	cin >> e;

	vector<vector<int>> roads(e, vector<int>(3));
	for (int i = 0; i < e; i++) {
		cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
	}

	cout << countPaths(n, roads) << endl;

	return 0;
}