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

#define vi vector<int>
int maxAns;
void buildTree(vector<vi> &edges, vector<list<int>> &tr, int n) {
	tr.clear();
	tr.resize(n);

	for (auto &e : edges) {
		tr[e[0]].push_back(e[1]);
		tr[e[1]].push_back(e[0]);

	}
}

void dfs(int node, vector<list<int>> &tr, vi &vis, vi &parent, vi &dist) {

	vis[node] = 1;

	for (auto &neigh : tr[node]) {
		if (! vis[neigh]) {
			dist[neigh] = dist[node] + 1;
			parent[neigh] = node;
			dfs(neigh, tr, vis, parent, dist);
		}
	}
}



void getMaxPath(int node, int curr, vector<list<int>> &tr, vector<int> &vis, vector<int> &amount) {

	vis[node] = 1;
	curr += amount[node];
	bool isleaf = 1;
	for (auto &neigh : tr[node]) {
		if (!vis[neigh]) {
			isleaf = 0;
			getMaxPath(neigh, curr, tr, vis, amount);
		}
	}

	if (isleaf) {
		maxAns = max(maxAns, curr);
	}

	curr -= amount[node];
}


int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

	int n = amount.size();
	vector<int> dist(n, 0), parent(n, 0);
	vector<int> vis(n, 0);
	vector<list<int>> tr;
	buildTree(edges, tr, n);


	// Now first I will populate the parent and the dist array;
	dfs(0, tr, vis, parent, dist);


	// Now I am going to update the amount array according to bob
	int currdist = 0;
	while (bob != 0) {
		if (currdist < dist[bob]) {
			amount[bob] = 0;
			currdist++;
		}
		else if (currdist == dist[bob]) {
			amount[bob] /= 2;
			currdist++;
		}

		bob = parent[bob];
	}

	maxAns = INT_MIN;
	for (auto &i : vis) i = 0;
	getMaxPath(0, 0, tr, vis, amount);

	return maxAns;
}

int main() {
	FIO();

	int n;
	cin >> n;
	int e;
	cin >> e;

	vector<vector<int>> edges(e, vector<int>(2));
	for (int i = 0; i < e; i++) {
		cin >> edges[i][0] >> edges[i][1];
	}

	int bob;
	cin >> bob;

	vector<int> amount(n);
	for (int i = 0; i < n; i++) {
		cin >> amount[i];
	}


	int ans = mostProfitablePath(edges, bob, amount);
	cout << ans << endl;


	return 0;
}