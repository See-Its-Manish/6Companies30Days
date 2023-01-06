#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isRectangleCover(vector<vector<int>>& rectangles) {

	int n = rectangles.size();
	map<pair<int,int>,int> mp;


	for(auto &v : rectangles) {
		mp[{v[0],v[1]}]++;
		mp[{v[2],v[3]}]++;
		mp[{v[0],v[3]}]--;
		mp[{v[2],v[1]}]--;
	}

	int corners = 0;
	for(auto &p : mp) {
		if(p.second != 0) {
			if(abs(p.second) == 1) corners++;
			else return 0;
		}
	}
	return (corners == 4);

}

int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 int n;
	 cin>>n;

	 vector<vector<int>> rectangles(n,vector<int>(4));

	 for(int i = 0; i < n; i++) {
	 	for(int j = 0; j < 4; j++) {
	 		cin>>rectangles[i][j];
	 	}
	}

	cout << isRectangleCover(rectangles) << endl;

}