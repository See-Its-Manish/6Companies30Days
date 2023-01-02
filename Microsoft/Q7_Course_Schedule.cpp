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
vector<list<int>> gr;
bool isCyclic(int node, vector<int> &vis, vector<int> &dfsvis) {

	vis[node] = 1;
	dfsvis[node] = 1;

	for (auto &neigh : gr[node] ) {
		if (!vis[neigh]) {
			if (isCyclic(neigh, vis, dfsvis)) return 1;
		}
		else if (dfsvis[neigh]) {
			return 1;
		}
	}

	dfsvis[node] = 0;
	return 0;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

	gr.clear();
	gr.resize(numCourses);
	for (int i = 0; i < prerequisites.size(); i++) {
		gr[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}

	vector<int> vis(numCourses, 0), dfsvis(numCourses, 0);

	for (int i = 0; i < numCourses; i++) {
		if (!vis[i]) {
			if (isCyclic(i, vis, dfsvis)) {

				return 0;
			}
		}
	}

	return 1;
}



int main() {
	FIO();

	int numCourses;
	cin >> numCourses;

	int prerequisiteslen;
	cin >> prerequisiteslen;

	vector<vector<int>> prerequisites(prerequisiteslen, vector<int>(2));
	for (int i = 0; i < prerequisiteslen; i++) {
		cin >> prerequisites[i][0] >> prerequisites[i][1];
	}

	cout << canFinish(numCourses, prerequisites) << endl;

	return 0;
}